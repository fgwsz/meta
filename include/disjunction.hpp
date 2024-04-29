#pragma once
#include"bool_constant.hpp"
#include"conditional.hpp"
// ||
template<typename... _TI_BoolConstants>
struct Disjunction
    :false_type
{};
template<typename _TI_BoolConstant0>
struct Disjunction
    <_TI_BoolConstant0>:_TI_BoolConstant0
{};
template<typename _TI_BoolConstant0,typename... _TI_BoolConstantN>
struct Disjunction
    <_TI_BoolConstant0,_TI_BoolConstantN...>:
    conditional_t<
        bool(_TI_BoolConstant0::value),
        _TI_BoolConstant0,
        Disjunction<_TI_BoolConstantN...>
    >
{};
template<typename... _TI_BoolConstants>
static constexpr bool disjunction_v=Disjunction<_TI_BoolConstants...>::value;
