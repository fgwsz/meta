#pragma once
#include"bool_constant.hpp"
template<typename _Type>
struct IsFunction
    :false_type
{};
#define EMPTY
#define IS_FUNCTION_IMPL(__EXT__) \
template<typename _Ret,typename... _Args> \
struct IsFunction \
    <_Ret(_Args...) __EXT__ >:true_type \
{}; \
template<typename _Ret,typename... _Args> \
struct IsFunction \
    <_Ret(_Args...,...) __EXT__ >:true_type \
{}; \
template<typename _Ret,typename... _Args> \
struct IsFunction \
    <_Ret(_Args...) __EXT__ noexcept>:true_type \
{}; \
template<typename _Ret,typename... _Args> \
struct IsFunction \
    <_Ret(_Args...,...) __EXT__ noexcept>:true_type \
{}; \
//
IS_FUNCTION_IMPL(EMPTY)
IS_FUNCTION_IMPL(const)
IS_FUNCTION_IMPL(volatile)
IS_FUNCTION_IMPL(const volatile)
IS_FUNCTION_IMPL(&)
IS_FUNCTION_IMPL(const&)
IS_FUNCTION_IMPL(volatile&)
IS_FUNCTION_IMPL(const volatile&)
IS_FUNCTION_IMPL(&&)
IS_FUNCTION_IMPL(const&&)
IS_FUNCTION_IMPL(volatile&&)
IS_FUNCTION_IMPL(const volatile&&)
#undef IS_FUNCTION_IMPL
template<typename _Type>
static constexpr bool is_function_v=IsFunction<_Type>::value;
