#pragma once

#include <type_traits>

namespace drgn
{

template<typename T>
using base_type = typename std::remove_cv<typename std::remove_reference<T>::type>::type;

template <class...>
struct type_list {
  using type = type_list;
};

template <class>
struct function_traits;

template <class R, class... TArgs>
struct function_traits<R (*)(TArgs...)> {
  using result_type = R;
  using args = type_list<TArgs...>;
};

template <class R, class... TArgs>
struct function_traits<R(TArgs...)> {
  using result_type = R;
  using args = type_list<TArgs...>;
};

template <class R, class T, class... TArgs>
struct function_traits<R (T::*)(TArgs...)> {
  using result_type = R;
  using args = type_list<TArgs...>;
};

template <class R, class T, class... TArgs>
struct function_traits<R (T::*)(TArgs...) const> {
  using result_type = R;
  using args = type_list<TArgs...>;
};

template <class T>
void print_type() {
    T::this_method_Sh0uldNotExist_();
}

}