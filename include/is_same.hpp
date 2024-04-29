#pragma once
#include"bool_constant.hpp"
template<typename _Lhs,typename _Rhs>
struct IsSame
    :false_type
{};
template<typename _Type>
struct IsSame
    <_Type,_Type>:true_type
{};
template<typename _Lhs,typename _Rhs>
static constexpr bool is_same_v=IsSame<_Lhs,_Rhs>::value;
