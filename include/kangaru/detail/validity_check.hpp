#ifndef KGR_KANGARU_INCLUDE_KANGARU_DETAIL_VALIDITY_CHECK_HPP
#define KGR_KANGARU_INCLUDE_KANGARU_DETAIL_VALIDITY_CHECK_HPP

#include "invoke_function.hpp"
#include "single.hpp"
#include "service_check.hpp"
#include "autocall_traits.hpp"

namespace kgr {
namespace detail {

/*
 * Check if a call for kgr::Container::service has no arguments in the case of a single service
 */
template<typename T, typename... Args>
using is_single_no_args = std::integral_constant<bool,
	!is_single<T>::value || meta_list_empty<meta_list<Args...>>::value
>;

/*
 * Complete validity check for a particlar service and all it's properties
 */
template<typename T, typename... Args>
struct is_construction_valid : std::integral_constant<bool,
	service_check<T, Args...>::value &&
	is_autocall_valid<T>::value &&
	dependency_trait<is_autocall_valid, T, Args...>::value
> {};

/*
 * Complete validity check for a particlar service and all it's properties
 */
template<typename T, typename... Args>
struct is_service_valid : std::integral_constant<bool,
	is_single_no_args<T, Args...>::value &&
	is_construction_valid<T, Args...>::value
> {};

/*
 * Metafunction that returns a partially applied trait.
 * Condition for is_invoke_service_valid.
 */
template<typename Map, typename T>
struct curry_is_invoke_service_valid {
	template<typename U>
	using mapped_t = mapped_service_t<U, Map>;

	template<typename... Services>
	using trait = all_of_traits<meta_list<detected_t<mapped_t, Services>...>, is_service_valid>;
};

/* 
 * Trait that check if a function is invocable, and all it's injected arguments are valid.
 */
template<typename Map, typename T, typename... Args>
using is_invoke_service_valid = bool_constant<
	is_detected<invoke_function_arguments_t, Map, T, Args...>::value &&
	expand_minus_n<
		sizeof...(Args),
		detected_or<meta_list<>, invoke_function_arguments_t, Map, T, Args...>,
		curry_is_invoke_service_valid<Map, T>::template trait
	>::value
>;

/*
 * Validity check for a invoke expression
 */
template<typename Map, typename T, typename... Args>
struct is_invoke_valid : bool_constant<
	is_invoke_service_valid<Map, T, Args...>::value &&
	is_invokable<Map, T, Args...>::value
> {};

} // namespace detail
} // namespace kgr

#endif // KGR_KANGARU_INCLUDE_KANGARU_DETAIL_VALIDITY_CHECK_HPP
