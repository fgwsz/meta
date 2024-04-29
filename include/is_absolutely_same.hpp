#pragma once
#include"bool_constant.hpp"
template<typename _Lhs,typename _Rhs>
struct IsAbsolutelySame
    :false_type
{};
template<typename _Type>
struct IsAbsolutelySame
    <_Type,_Type>:true_type
{};
template<typename _Lhs,typename _Rhs>
static constexpr bool is_absolutely_same_v=IsAbsolutelySame<_Lhs,_Rhs>::value;
