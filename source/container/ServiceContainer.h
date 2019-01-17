#pragma once

#include "Result.h"
#include "TypeId.h"
#include "TypeTraits.h"
#include "ConstructorTraits.h"

#include <assert.h>
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

namespace drgn {

class ServiceContainer;

template <class, class, class, class>
struct Factory;

template <class T, class Creater, class Destroyer, class... Args>
struct Factory<T, Creater, Destroyer, type_list<Args...>> {
    static Result Create(Creater f, ServiceContainer& container, T** instance)
    {
        Result tests[] = { ResultSuccess(), container.Initialize<base_type<Args>>()... };
        bool test = true;
        for (int i = 0; i < sizeof...(Args) + 1; i++)
        {
            DRGN_RETURN_IF_FAILURE(tests[i]);
        }

        *instance = f(container.GetOrCreate<base_type<Args>>()...);
        return ResultSuccess();
    }
    static Result Destroy(Destroyer f, T* instance)
    {
        f(instance);
        return ResultSuccess();
    }
};

template <class T, class>
struct ConstructorFactory;

template <class T, class... Args>
struct ConstructorFactory<T, drgn::type_list<Args...>> {
    static Result Create(ServiceContainer& container, T** instance)
    {
        *instance = new T(Args{ container }...);
        return ResultSuccess();
    }
    static Result Destroy(T* instance)
    {
        delete instance;
        return ResultSuccess();
    }
};

class ServiceContainer {
    template<class T>
    friend struct any_type;

    template <class, class, class, class>
    friend struct Factory;

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

        bool IsInitialized() const
        {
            return m_status == Status::IsInitialized;
        }

        Status GetStatus() const
        {
            return m_status;
        }

        virtual Result Initialize(ServiceContainer& container) = 0;
        virtual Result Finalize(ServiceContainer& container) = 0;

        virtual void* Get() const = 0;

    protected:
        TypeId m_id;
        Status m_status;
    };

    template <class T>
    class Service : public ServiceBase {
    public:
        using InitializerFunc = std::function<Result(ServiceContainer&, T**)>;
        using FinalizerFunc = std::function<Result(T*)>;

        Service(TypeId id, InitializerFunc&& initializer, FinalizerFunc&& finalizer)
            : ServiceBase(id)
            , m_initializer(std::move(initializer))
            , m_finalizer(std::move(finalizer))
        {
        }

        Result Initialize(ServiceContainer& container) override
        {
            assert(m_status != Status::IsInitialized);
            if (m_status == Status::StartInitializing)
            {
                return Result(false, "Circular dependency detected");
            }
            m_status = Status::StartInitializing;

            Result r = m_initializer(container, &m_instance);
            if (!r.IsSuccess())
            {
                m_status = Status::NotInitialized;
                return r;
            } else {
                m_status = Status::IsInitialized;
                return ResultSuccess();            
            }
        }

        void* Get() const
        {
            return m_instance;
        }

        Result Finalize(ServiceContainer& container) override
        {
            m_instance = nullptr;
            m_status = Status::NotInitialized;
            return m_finalizer(m_instance);
        }

    private:
        T* m_instance = nullptr;
        InitializerFunc m_initializer;
        FinalizerFunc m_finalizer;
    };

public:
    template <class T, class CreateFunc, class DestroyFunc>
    void Register(CreateFunc creater, typename DestroyFunc destroyer)
    {
        static_assert(std::is_same_v<T*, drgn::function_traits<CreateFunc>::result_type>, "Type registered and type returned by the creater are different");
        using Factory = Factory<T, CreateFunc, DestroyFunc, typename function_traits<CreateFunc>::args>;
        auto initializer = [this, creater](ServiceContainer& container, T** instance) -> Result {
            return Factory::Create(creater, *this, instance);
        };
        auto finalizer = [this, destroyer](T* instance) -> Result {
            return Factory::Destroy(destroyer, instance);
        };
        RegisterImpl<T>(initializer, finalizer);
    }

    template <class T, int CtorArgN = 10>
    void Register()
    {
        using ctor = drgn::ctor_traits<T, CtorArgN>;
        static_assert(typename ctor::is_constructible, "ServiceContainer::Register<T>() has failed to be instanciated" 
            "\nerror: Does the constructor of T only use reference (Arg&) or pointer (Arg*) argument?"
            "\nerror: Does the constructor of T depens on itself (T& or T*)?"
            "\nerror: Does the number of argument of T constructor < CtorArgN? If so you can change number by calling: Register<T, CtorArgN>()"
        );
        using Factory = drgn::ConstructorFactory<T, ctor::args>;

        auto constructor = [](ServiceContainer& container, T** instance) -> Result { 
            Result r =Factory::Create(container, instance); 
            DRGN_RETURN_IF_FAILURE(r);
            return ResultSuccess();
        };
        auto destructor = [] (T* instance) -> Result { 
            Result r = Factory::Destroy(instance); 
            DRGN_RETURN_IF_FAILURE(r);
            return ResultSuccess();
        };
        RegisterImpl<T>(constructor, destructor);
    }

    Result Initialize()
    {
        for (const auto& s : m_services) {
            Result r = TryInitializeService(s.second);
            DRGN_RETURN_IF_FAILURE(r);
        }
        return ResultSuccess();
    }

    template <class T>
    T& Get()
    {
        TypeId id = TypeId::Get<T>();
        auto iter = m_services.find(id);
        assert(iter != m_services.end());

        std::shared_ptr<ServiceBase> service = iter->second;

        assert(service->IsInitialized());

        return *reinterpret_cast<T*>(service->Get());
    }

    template <class T>
    bool IsRegister()
    {
        TypeId id = TypeId::Get<T>();
        auto iter = m_services.find(id);
        return (iter != m_services.end());
    }
    template <class T>
    bool IsInitialized()
    {
        TypeId id = TypeId::Get<T>();
        auto iter = m_services.find(id);
        if (iter == m_services.end())
        {
            return false;
        }
        else
        {
            return iter->second->IsInitialized();
        }
    }

protected:
    template <class T>
    T& GetOrCreate()
    {
        TypeId id = TypeId::Get<T>();
        auto iter = m_services.find(id);
        assert(iter != m_services.end());

        std::shared_ptr<ServiceBase> service = iter->second;

        Result r = TryInitializeService(service);
        assert(r.IsSuccess());

        return *reinterpret_cast<T*>(service->Get());
    }

    template <class T>
    bool InitializationPending()
    {
        TypeId id = TypeId::Get<T>();
        auto iter = m_services.find(id);
        if (iter == m_services.end()) {
            return false;
        } else {
            return iter->second->GetStatus() == ServiceBase::Status::StartInitializing;
        }
    }

    template <class T>
    Result Initialize()
    {
        TypeId id = TypeId::Get<T>();
        auto iter = m_services.find(id);
        if (iter == m_services.end()) {
            return Result(false, "Service does not exist");
        } else {
            Result r = TryInitializeService(iter->second);
            DRGN_RETURN_IF_FAILURE(r);
        }

        return ResultSuccess();
    }

    Result TryInitializeService(std::shared_ptr<ServiceBase> service)
    {
        if (!service->IsInitialized()) {
            Result r = service->Initialize(*this);
            DRGN_RETURN_IF_FAILURE(r);

            m_serviceOrder.push_back(service);
        }

        return ResultSuccess();
    }

    protected:
    template <class T>
    void RegisterImpl(typename Service<T>::InitializerFunc initializer, typename Service<T>::FinalizerFunc finalizer)
    {
        auto id = TypeId::Get<T>();
        m_services.emplace(id, std::make_shared<Service<T>>(id, std::move(initializer), std::move(finalizer)));
    }

private:
    std::unordered_map<TypeId, std::shared_ptr<ServiceBase>> m_services;
    std::vector<std::weak_ptr<ServiceBase>> m_serviceOrder;
};
}
