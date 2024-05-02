#pragma once
#include"bool_constant.hpp"
template<
    typename _TI_BoolConstant
    ,typename _TrueCase
    ,typename _FalseCase
>
struct IfThenElse{
    using type=_FalseCase;
};
template<
    typename _TrueCase
    ,typename _FalseCase
>
struct IfThenElse
    <true_type,_TrueCase,_FalseCase>{
    using type=_TrueCase;
};
template<
    typename _TI_BoolConstant
    ,typename _TrueCase
    ,typename _FalseCase
>
using if_then_else_t=typename IfThenElse<
    _TI_BoolConstant
    ,_TrueCase
    ,_FalseCase
>::type;