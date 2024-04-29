#pragma once
#include"bool_constant.hpp"
#include"conditional.hpp"
// &&
template<typename... _TI_BoolConstants>
struct Conjunction
    :true_type
{};
template<typename _TI_BoolConstant0>
struct Conjunction
    <_TI_BoolConstant0>:_TI_BoolConstant0
{};
template<typename _TI_BoolConstant0,typename... _TI_BoolConstantN>
struct Conjunction
    <_TI_BoolConstant0,_TI_BoolConstantN...>:
    conditional_t<
        bool(_TI_BoolConstant0::value),
        Conjunction<_TI_BoolConstantN...>,
        _TI_BoolConstant0
    >
{};
template<typename... _TI_BoolConstants>
static constexpr bool conjunction_v=Conjunction<_TI_BoolConstants...>::value;
