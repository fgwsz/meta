#pragma once
#include"bool_constant.hpp"
#include"conditional.hpp"
// &&
template<typename... _TI_BoolConstant_N>
struct Conjunction
    :true_type
{};
template<typename _TI_BoolConstant_1>
struct Conjunction
    <_TI_BoolConstant_1>:_TI_BoolConstant_1
{};
template<typename _TI_BoolConstant_1,typename... _TI_BoolConstant_N>
struct Conjunction
    <_TI_BoolConstant_1,_TI_BoolConstant_N...>:
    conditional_t<
        bool(_TI_BoolConstant_1::type::value),
        Conjunction<_TI_BoolConstant_N...>,
        _TI_BoolConstant_1
    >
{};
template<typename... _TI_BoolConstant_N>
static constexpr bool conjunction_v=Conjunction<_TI_BoolConstant_N...>::type::value;
