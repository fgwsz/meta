#pragma once
#include"bool_constant.hpp"
#include"remove_cv.hpp"
template<typename _Lhs,typename _Rhs>
struct IsSameHelper
    :false_type
{};
template<typename _Type>
struct IsSameHelper
    <_Type,_Type>:true_type
{};
template<typename _Lhs,typename _Rhs>
struct IsSame
    :IsSameHelper<remove_cv_t<_Lhs>,remove_cv_t<_Rhs>>
{};
template<typename _Lhs,typename _Rhs>
static constexpr bool is_same_v=IsSame<_Lhs,_Rhs>::value;
