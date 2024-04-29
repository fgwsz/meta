#pragma once
#include"bool_constant.hpp"
template<typename _Type>
struct IsConst
    :false_type
{};
template<typename _Type>
struct IsConst
    <_Type const>:true_type
{};
template<typename _Type>
static constexpr bool is_const_v=IsConst<_Type>::value;
