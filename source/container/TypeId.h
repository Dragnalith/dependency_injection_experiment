#pragma once

#include <unordered_map>

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