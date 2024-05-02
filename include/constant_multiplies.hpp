#pragma once
#include"auto_constant.hpp"
namespace detail{
// decl
template<
    typename _TI_Constant_1
    ,typename... _TI_Constant_N
>
struct ConstantMultipliesHelper;
// impl 1
template<typename _TI_Constant_1>
struct ConstantMultipliesHelper
    <_TI_Constant_1>:_TI_Constant_1
{};
// impl 2
template<
    typename _TI_Constant_1
    ,typename _TI_Constant_2
    ,typename... _TI_Constant_N
>
struct ConstantMultipliesHelper
    <_TI_Constant_1,_TI_Constant_2,_TI_Constant_N...>
    :ConstantMultipliesHelper<
        auto_constant<
            _TI_Constant_1::type::value*_TI_Constant_2::type::value
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
struct ConstantMultiplies
    :detail::ConstantMultipliesHelper<
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
using constant_multiplies_t=typename ConstantMultiplies<
    _TI_Constant_1
    ,_TI_Constant_2
    ,_TI_Constant_N...
>::type;
