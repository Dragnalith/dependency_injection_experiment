#pragma once

#include "TypeTraits.h"
#include "ServiceContainer.h"

#include <type_traits>
#include <utility>

namespace drgn
{

class ServiceContainer;

template<class TParent>
struct any_type {
    template <class T,
        class = std::enable_if_t<!std::is_same_v<const TParent, T> && !std::is_same_v<TParent, T>>>
    operator T&() const
    {
        return container.GetOrCreate<T>();
    }

    template <class T,
        class = std::enable_if_t<!std::is_same_v<const TParent, T> && !std::is_same_v<TParent, T>>>
    operator T*() const
    {
        return &container.Get<T>();
    }

    ServiceContainer& container;
};

namespace detail {

template <class T, int>
using get = T;

template <class T, class, class = int>
struct ctor_traits
{
    using args = type_list<>;
    static constexpr bool is_constructible = true;
};

template <class T>
struct ctor_traits<T, std::index_sequence<>, std::enable_if_t<std::is_constructible_v<T>>> {
    using args = type_list<>;
    static constexpr bool is_constructible = true;
};

template <class T>
struct ctor_traits<T, std::index_sequence<>, std::enable_if_t<!std::is_constructible_v<T>>> {
    using args = type_list<>;
    static constexpr bool is_constructible = false;
};

template <class T>
struct ctor_traits<T, std::index_sequence<0>, std::enable_if_t<std::is_constructible_v<T, any_type<T>>>> {
    using args = type_list<any_type<T>>;
    static constexpr bool is_constructible = true;
};

template <class T>
struct ctor_traits<T, std::index_sequence<0>, std::enable_if_t<!std::is_constructible_v<T, any_type<T>>>> {
    using next = typename ctor_traits<T, std::index_sequence<>, void>;
    using args = typename next::args;
    static constexpr bool is_constructible = typename next::is_constructible;
};

template <class T, int ... Ns>
struct ctor_traits<T, std::index_sequence<Ns...>, std::enable_if_t<std::is_constructible_v<T, get<any_type<T>, Ns>...>>> 
{
    using args = type_list<get<any_type<T>, Ns>...>;
    static constexpr bool is_constructible = true;
};

template <class T, int ... Ns>
struct ctor_traits<T, std::index_sequence<Ns...>, std::enable_if_t<!std::is_constructible_v<T, get<any_type<T>, Ns>...>>> 
{
    using next = typename ctor_traits<T, std::make_index_sequence<sizeof...(Ns) - 1>, void>;
    using args = typename next::args;
    static constexpr bool is_constructible = typename next::is_constructible;
};

}

template<class T, int N = 10>
using ctor_traits = typename detail::ctor_traits<T, std::make_index_sequence<N>, void>;

}
