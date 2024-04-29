#pragma once
#include"bool_constant.hpp"
template<typename _Type>
struct IsRValueReference
    :false_type
{};
template<typename _Type>
struct IsRValueReference
    <_Type&&>:true_type
{};
template<typename _Type>
static constexpr bool is_rvalue_reference_v=IsRValueReference<_Type>::value;
