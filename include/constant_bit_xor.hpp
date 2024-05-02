#pragma once
#include"auto_constant.hpp"
template<typename _TI_Constant_1,typename _TI_Constant_2>
struct ConstantBitXor
    :auto_constant<
        _TI_Constant_1::type::value^_TI_Constant_2::type::value
    >
{};
template<typename _TI_Constant_1,typename _TI_Constant_2>
using constant_bit_xor_t=typename ConstantBitXor<
    _TI_Constant_1
    ,_TI_Constant_2
>::type;
