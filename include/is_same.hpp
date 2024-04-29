#pragma once
#include"is_absolutely_same.hpp"
#include"remove_cv.hpp"
template<typename _Lhs,typename _Rhs>
struct IsSame
    :IsAbsolutelySame<remove_cv_t<_Lhs>,remove_cv_t<_Rhs>>
{};
template<typename _Lhs,typename _Rhs>
static constexpr bool is_same_v=IsSame<_Lhs,_Rhs>::value;
