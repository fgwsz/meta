#pragma once
#include"bool_constant.hpp"
template<typename _TI_BoolConstant>
struct Negation
    :bool_constant<!bool(_TI_BoolConstant::type::value)>
{};
template<typename _TI_BoolConstant>
static constexpr bool negation_v=Negation<_TI_BoolConstant>::type::value;
