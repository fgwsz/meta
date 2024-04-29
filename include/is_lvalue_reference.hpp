#pragma once
#include"bool_constant.hpp"
template<typename _Type>
struct IsLValueReference
    :false_type
{};
template<typename _Type>
struct IsLValueReference
    <_Type&>:true_type
{};
template<typename _Type>
static constexpr bool is_lvalue_reference_v=IsLValueReference<_Type>::value;
