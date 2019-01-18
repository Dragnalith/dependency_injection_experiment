#pragma once

#include <unordered_map>
#include <string>
#include <type_traits>

#if 0

namespace drgn
{

namespace detail
{

template<typename T>
struct TypeIdPtr {
	// Having a static data member will ensure us that it has only one address for the whole program.
	// Furthermore, the static data member having different types will ensure it won't get optimized.
	static const T* const Id;
};

template<typename T>
const T* const TypeIdPtr<T>::Id = nullptr;

} // namespace detail

struct TypeId
{
    const void* Id;

    bool operator==(const TypeId &other) const
    {
        return other.Id == Id;
    }

    template <typename T>
    static constexpr TypeId Get() {
        return TypeId{ &detail::TypeIdPtr<T>::Id };
    }

    static constexpr TypeId Invalid()
    {
        return TypeId{ nullptr };
    }
};

}
namespace std
{
    template <>
    struct hash<drgn::TypeId>
    {
        size_t operator()(const drgn::TypeId& k) const
        {
            std::hash<void*> hash;
            return hash((void*)k.Id);
        }
    };
}

#else
namespace drgn {

namespace detail {

constexpr size_t SkipSizeAtBegin = 36;
constexpr size_t SkipSizeAtEnd = 7;

inline size_t GetSize(const char* s)
{
    return (std::char_traits<char>::length(s) - SkipSizeAtEnd);
}

constexpr const char* ExtractSignature(const char* signature)
{
    return &signature[SkipSizeAtBegin];
}

template <typename T>
const char* f()
{
    return ExtractSignature(
#if defined(_MSC_VER)
        __FUNCSIG__
#elif defined(__clang__)
        __PRETTY_FUNCTION__
#elif defined(__GNUC__)
        __PRETTY_FUNCTION__
#else
#error "Signature extraction not implemented for your compiler"
#endif
    );
}

} // namespace detail

class TypeId {
    friend struct std::hash<TypeId>;

public:
    template <typename T>
    static TypeId Get()
    {
        static std::string name(detail::f<T>(), detail::GetSize(detail::f<T>()));
        return TypeId(name);
    }

    bool operator==(TypeId s) const
    {
        return m_id.compare(s.m_id) == 0;
    }

    const char* GetName() const
    {
        return m_id.c_str();
    }

private:
    TypeId(const std::string& id)
        : m_id(id)
    {
    }
    const std::string& m_id;
};

}

namespace std {

template <>
struct hash<drgn::TypeId> {
    size_t operator()(const drgn::TypeId& x) const
    {
        return hash<std::string>{}(x.m_id);
    }
};
}

#endif
