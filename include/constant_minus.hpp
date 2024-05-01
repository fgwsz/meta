#pragma once
#include"constant.hpp"
namespace detail{
// decl
template<
    typename _TI_Constant_1
    ,typename... _TI_Constant_N
>
struct ConstantMinusHelper;
// impl 1
template<typename _TI_Constant_1>
struct ConstantMinusHelper
    <_TI_Constant_1>{
    using type=_TI_Constant_1;
};
// impl 2
template<
    typename _TI_Constant_1
    ,typename _TI_Constant_2
    ,typename... _TI_Constant_N
>
struct ConstantMinusHelper
    <_TI_Constant_1,_TI_Constant_2,_TI_Constant_N...>{
private:
    static constexpr auto value=
        _TI_Constant_1::type::value-_TI_Constant_2::type::value;
    using value_type=decltype(value);
    using current_result=Constant<value_type,value>;
public:
    using type=typename ConstantMinusHelper<
        current_result
        ,_TI_Constant_N...
    >::type;
};
}//namespace detail
template<
    typename _TI_Constant_1,
    typename _TI_Constant_2,
    typename... _TI_Constant_N
>
struct ConstantMinus{
    using type=typename detail::ConstantMinusHelper<
        _TI_Constant_1
        ,_TI_Constant_2
        ,_TI_Constant_N...
    >::type;
};
template<
    typename _TI_Constant_1,
    typename _TI_Constant_2,
    typename... _TI_Constant_N
>
using constant_minus_t=typename ConstantMinus<
    _TI_Constant_1
    ,_TI_Constant_2
    ,_TI_Constant_N...
>::type;
