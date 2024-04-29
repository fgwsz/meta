#pragma once
#include"bool_constant.hpp"
template<typename _Type>
struct IsVolatile
    :false_type
{};
template<typename _Type>
struct IsVolatile
    <_Type volatile>:true_type
{};
template<typename _Type>
static constexpr bool is_volatile_v=IsVolatile<_Type>::value;
