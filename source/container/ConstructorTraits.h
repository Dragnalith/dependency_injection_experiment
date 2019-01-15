#pragma once

#include "TypeTraits.h"
#include "ServiceContainer.h"

#include <type_traits>
#include <utility>

namespace drgn
{

class ServiceContainer;

struct any_type {
    template <class T>
    operator T&() const
    {
        return container.Get<T>();
    }

    template <class T>
    operator T*() const
    {
        return &container.Get<T>();
    }

    ServiceContainer& container;
};

namespace detail
{

template <class T, int>
using get = T;

template <class T, class, class = int>
struct ctor_traits;

template <class T>
struct ctor_traits<T, std::index_sequence<>, std::enable_if_t<std::is_constructible_v<T>>> 
{
    using args = type_list<>;
};

template <class T>
struct ctor_traits<T, std::index_sequence<0>, std::enable_if_t<std::is_constructible_v<T, any_type>>> {
    using args = type_list<any_type>;
};

template <class T>
struct ctor_traits<T, std::index_sequence<0>, std::enable_if_t<!std::is_constructible_v<T, any_type>>> {
    using args = typename ctor_traits<T, std::index_sequence<>, void>::args;
};

template <class T, int ... Ns>
struct ctor_traits<T, std::index_sequence<Ns...>, std::enable_if_t<std::is_constructible_v<T, get<any_type, Ns>...>>> 
{
    using args = type_list<get<any_type, Ns>...>;
};

template <class T, int ... Ns>
struct ctor_traits<T, std::index_sequence<Ns...>, std::enable_if_t<!std::is_constructible_v<T, get<any_type, Ns>...>>> 
{
    using args = typename ctor_traits<T, std::make_index_sequence<sizeof...(Ns) - 1>, void>::args;
};

}

template<class T, int N = 10>
using ctor_args = typename detail::ctor_traits<T, std::make_index_sequence<N>, void>::args;

}