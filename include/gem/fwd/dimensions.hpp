#ifndef FWD_DIMENSIONS_HPP_INCLUDED
#define FWD_DIMENSIONS_HPP_INCLUDED

#include <limits>

#include <gem/concept/dimensions.hpp>

namespace gem {

template <typename T, T cv, T max_cv, T min_cv>
class Dimension;

template <typename T>
constexpr inline auto Dim(const T& value);

namespace detail {

template <typename>
struct is_gem_dimension_impl;

template <typename>
struct is_gem_runtime_dimension_impl;

template <typename>
struct is_gem_compile_time_dimension_impl;

template <typename T>
using is_gem_dimension = is_gem_dimension_impl<std::decay_t<T>>;

template <typename T>
using is_gem_dimension_t = typename is_gem_dimension<T>::type;

template <typename T>
constexpr auto is_gem_dimension_v = is_gem_dimension<T>::value;

template <typename T>
using is_gem_runtime_dimension =
    is_gem_runtime_dimension_impl<std::decay_t<T>>;

template <typename T>
using is_gem_runtime_dimension_t =
    typename is_gem_runtime_dimension<T>::type;

template <typename T>
constexpr auto is_gem_runtime_dimension_v =
    is_gem_runtime_dimension<T>::value;

template <typename T>
using is_gem_compile_time_dimension =
    is_gem_runtime_dimension_impl<std::decay_t<T>>;

template <typename T>
using is_gem_compile_time_dimension_t =
    typename is_gem_runtime_dimension<T>::type;

template <typename T>
constexpr auto is_gem_compile_time_dimension_v =
    is_gem_compile_time_dimension<T>::value;

}  // namespace detail

}  // namespace gem

template <class T>
concept bool GemDimension = gem::detail::is_gem_dimension_v<T>;

template <class T>
concept bool GemRuntimeDimension =
    gem::detail::is_gem_runtime_dimension_v<T>;

template <class T>
concept bool GemCompileTimeDimension =
    gem::detail::is_gem_compile_time_dimension_v<T>;

#endif  // !FWD_DIMENSIONS_HPP_INCLUDED