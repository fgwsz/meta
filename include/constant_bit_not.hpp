#pragma once
#include"constant.hpp"
template<typename _TI_Constant>
struct ConstantBitNot{
private:
    static constexpr auto value=~_TI_Constant::type::value;
    using value_type=decltype(value);
public:
    using type=Constant<value_type,value>;
};
template<typename _TI_Constant>
using constant_bit_not_t=typename ConstantBitNot<_TI_Constant>::type;
