#pragma once
#include"bool_constant.hpp"
#include"conditional.hpp"
// ||
template<typename... _TI_BoolConstant_N>
struct Disjunction
    :false_type
{};
template<typename _TI_BoolConstant_1>
struct Disjunction
    <_TI_BoolConstant_1>:_TI_BoolConstant_1::type
{};
template<typename _TI_BoolConstant_1,typename... _TI_BoolConstant_N>
struct Disjunction
    <_TI_BoolConstant_1,_TI_BoolConstant_N...>:
    conditional_t<
        bool(_TI_BoolConstant_1::type::value),
        typename _TI_BoolConstant_1::type,
        Disjunction<_TI_BoolConstant_N...>
    >
{};
template<typename... _TI_BoolConstant_N>
static constexpr bool disjunction_v=Disjunction<_TI_BoolConstant_N...>::value;
