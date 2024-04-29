#pragma once
#include"bool_constant.hpp"
template<typename _Type>
struct IsPointer
    :false_type
{};
template<typename _Type>
struct IsPointer
    <_Type* const>:true_type
{};
template<typename _Type>
struct IsPointer
    <_Type* volatile>:true_type
{};
template<typename _Type>
struct IsPointer
    <_Type* const volatile>:true_type
{};
template<typename _Type>
static constexpr bool is_pointer_v=IsPointer<_Type>::value;
