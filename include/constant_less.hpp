#pragma once
#include"auto_constant.hpp"
template<typename _TI_Constant_1,typename _TI_Constant_2>
struct ConstantLess{
private:
    static constexpr auto value=
        _TI_Constant_1::type::value<_TI_Constant_2::type::value;
public:
    using type=auto_constant<value>;
};
template<typename _TI_Constant_1,typename _TI_Constant_2>
using constant_less_t=typename ConstantLess<
    _TI_Constant_1
    ,_TI_Constant_2
>::type;
