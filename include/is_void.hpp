#pragma once
#include"is_same.hpp"
#include"remove_cv.hpp"
template<typename _Type>
struct IsVoid
    :IsSame<void,remove_cv_t<_Type>>
{};
template<typename _Type>
static constexpr bool is_void_v=IsVoid<_Type>::value;
