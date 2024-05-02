#pragma once
#include"auto_constant.hpp"
template<typename _TI_Constant>
struct ConstantNot
    :auto_constant<!_TI_Constant::type::value>
{};
template<typename _TI_Constant>
using constant_not_t=typename ConstantNot<_TI_Constant>::type;
