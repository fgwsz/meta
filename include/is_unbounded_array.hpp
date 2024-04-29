#pragma once
#include"bool_constant.hpp"
template<typename _Type>
struct IsUnboundedArray
    :false_type
{};
template<typename _Type>
struct IsUnboundedArray
    <_Type[]>:true_type
{};
template<typename _Type>
static constexpr bool is_unbounded_array_v=IsUnboundedArray<_Type>::value;
