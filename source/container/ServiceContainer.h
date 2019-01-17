#pragma once

#include "Result.h"
#include "TypeId.h"
#include "TypeTraits.h"

#include <assert.h>
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

namespace drgn {

class ServiceContainer;

template <class, class, class>
struct Factory;

template <class T, class Func, class... Args>
struct Factory<T, Func, drgn::type_list<Args...>> {
    static T* Create(Func f, ServiceContainer& container)
    {
        return f(container.Get<base_type<Args>>()...);
    }
};

template <class T, class>
struct DefaultConstructor;

template <class T, class... Args>
struct DefaultConstructor<T, drgn::type_list<Args...>> {
    static T* Create(ServiceContainer& container)
    {
        return new T(Args{ container }...);
    }
    static void Destroy(T* instance)
    {
        delete instance;
    }
};

class ServiceContainer {
private:
    class ServiceBase {
    public:
        enum class Status {
            NotInitialized,
            StartInitializing,
            IsInitialized
        };

        virtual ~ServiceBase() = default;

        ServiceBase(TypeId id)
            : m_id(id)
            , m_status(Status::NotInitialized)
        {
        }

        bool IsInitialized()
        {
            return m_status == Status::IsInitialized;
        }

        virtual void Initialize(ServiceContainer& container) = 0;
        virtual void Finalize(ServiceContainer& container) = 0;

        virtual void* Get() const = 0;

    protected:
        TypeId m_id;
        Status m_status;
    };

    template <class T>
    class Service : public ServiceBase {
    public:
        using InitializerFunc = std::function<T*(ServiceContainer&)>;
        using FinalizerFunc = std::function<void(T*)>;

        Service(TypeId id, InitializerFunc&& initializer, FinalizerFunc&& finalizer)
            : ServiceBase(id)
            , m_initializer(std::move(initializer))
            , m_finalizer(std::move(finalizer))
        {
        }

        void Initialize(ServiceContainer& container) override
        {
            assert(m_status != Status::IsInitialized);
            assert(m_status != Status::StartInitializing);
            m_status = Status::StartInitializing;

            m_instance = m_initializer(container);
            m_status = Status::IsInitialized;
        }

        void* Get() const
        {
            return m_instance;
        }

        void Finalize(ServiceContainer& container) override
        {
            m_finalizer(m_instance);
            m_instance = nullptr;
            m_status = Status::NotInitialized;
        }

    private:
        T* m_instance = nullptr;
        InitializerFunc m_initializer;
        FinalizerFunc m_finalizer;
    };

protected:
    template <class T>
    void RegisterImpl(typename Service<T>::InitializerFunc initializer, typename Service<T>::FinalizerFunc finalizer)
    {
        auto id = TypeId::Get<T>();
        m_services.emplace(id, std::make_shared<Service<T>>(id, std::move(initializer), std::move(finalizer)));
        m_serviceOrder.push_back(m_services[id]);
    }

public:
    template <class T, class InitFunc>
    void Register(InitFunc creater, typename Service<T>::FinalizerFunc finalizer)
    {
        static_assert(std::is_same_v<T*, drgn::function_traits<InitFunc>::result_type>, "Type registered and type returned by the creater are different");

        auto initializer = [this, creater](ServiceContainer& container) -> T* {
            return drgn::Factory<T, InitFunc, typename drgn::function_traits<InitFunc>::args>::Create(creater, *this);
        };
        RegisterImpl<T>(initializer, finalizer);
    }

    template <class T, int CtorArgN = 10>
    void Register()
    {
        using ctor = drgn::ctor_traits<T, CtorArgN>;
        static_assert(typename ctor::is_constructible, "ServiceContainer::Register<T>() has failed to be instanciated" 
            "\nerror: Does the constructor of T only use reference (Arg&) or pointer (Arg*) argument?"
            "\nerror: Does the number of argument of T constructor < CtorArgN? If so you can change number by calling: Register<T, CtorArgN>()"
        );
        using Factory = drgn::DefaultConstructor<T, ctor::args>;

        auto constructor = [](ServiceContainer& container) -> T* { return Factory::Create(container); };
        auto destructor = [](T* instance) -> void { Factory::Destroy(instance); };
        RegisterImpl<T>(constructor, destructor);
    }

    void Initialize()
    {
        for (auto s : m_serviceOrder) {
            auto service = s.lock();
            if (!service->IsInitialized())
            {
                service->Initialize(*this);
            }
        }
    }

    template <class T>
    T& Get()
    {
        TypeId id = TypeId::Get<T>();
        auto iter = m_services.find(id);
        assert(iter != m_services.end());

        std::shared_ptr<ServiceBase> service = iter->second;

        return *reinterpret_cast<T*>(service->Get());
    }

private:
    std::unordered_map<TypeId, std::shared_ptr<ServiceBase>> m_services;
    std::vector<std::weak_ptr<ServiceBase>> m_serviceOrder;
};
}
