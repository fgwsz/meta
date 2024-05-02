#pragma once
#include"auto_constant.hpp"
template<typename _TI_Constant>
struct ConstantBitNot
    :auto_constant<~_TI_Constant::type::value>
{};
template<typename _TI_Constant>
using constant_bit_not_t=typename ConstantBitNot<_TI_Constant>::type;
