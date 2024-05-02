#pragma once
#include"auto_constant.hpp"
template<typename _TI_Constant>
struct ConstantNegate
    :auto_constant<-_TI_Constant::type::value>
{};
template<typename _TI_Constant>
using constant_negate_t=typename ConstantNegate<_TI_Constant>::type;
