#pragma once
#include"bool_constant.hpp"
template<typename _Type>
struct IsReference
    :false_type
{};
template<typename _Type>
struct IsReference
    <_Type&>:true_type
{};
template<typename _Type>
struct IsReference
    <_Type&&>:true_type
{};
template<typename _Type>
static constexpr bool is_reference_v=IsReference<_Type>::value;
