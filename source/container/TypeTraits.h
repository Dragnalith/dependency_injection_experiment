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

template <class T>
class has_initialize_t {
    template <typename C>
    static std::true_type test(decltype(&C::Initialize));
    template <typename C>
    static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

template <class T>
constexpr bool has_initialize = has_initialize_t<T>::value;

template <class T>
class has_finalize_t {
    template <typename C>
    static std::true_type test(decltype(&C::Finalize));
    template <typename C>
    static std::false_type test(...);
public:
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

template <class T>
constexpr bool has_finalize = has_finalize_t<T>::value;

}
