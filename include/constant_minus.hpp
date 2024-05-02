#pragma once
#include"auto_constant.hpp"
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
    <_TI_Constant_1>:_TI_Constant_1
{};
// impl 2
template<
    typename _TI_Constant_1
    ,typename _TI_Constant_2
    ,typename... _TI_Constant_N
>
struct ConstantMinusHelper
    <_TI_Constant_1,_TI_Constant_2,_TI_Constant_N...>
    :ConstantMinusHelper<
        auto_constant<
            _TI_Constant_1::type::value-_TI_Constant_2::type::value
        >
        ,_TI_Constant_N...
    >
{};
}//namespace detail
template<
    typename _TI_Constant_1,
    typename _TI_Constant_2,
    typename... _TI_Constant_N
>
struct ConstantMinus
    :detail::ConstantMinusHelper<
        _TI_Constant_1
        ,_TI_Constant_2
        ,_TI_Constant_N...
    >
{};
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
