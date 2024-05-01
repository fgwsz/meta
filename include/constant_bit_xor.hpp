#pragma once
#include"constant.hpp"
template<typename _TI_Constant_1,typename _TI_Constant_2>
struct ConstantBitXor{
private:
    static constexpr auto value=
        _TI_Constant_1::type::value^_TI_Constant_2::type::value;
    using value_type=decltype(value);
public:
    using type=Constant<value_type,value>;
};
template<typename _TI_Constant_1,typename _TI_Constant_2>
using constant_bit_xor_t=typename ConstantBitXor<
    _TI_Constant_1
    ,_TI_Constant_2
>::type;
