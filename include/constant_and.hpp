#pragma once
#include"bool_constant.hpp"
namespace detail{
// decl
template<typename... _TI_Constant_N>
struct ConstantAndHelper;
// impl 0
template<>
struct ConstantAndHelper
    <>:true_type
{};
// impl 1
template<typename... _TI_Constant_N>
struct ConstantAndHelper
    <true_type,_TI_Constant_N...>
    :ConstantAndHelper<_TI_Constant_N...>
{};
// impl 2
template<typename... _TI_Constant_N>
struct ConstantAndHelper
    <false_type,_TI_Constant_N...>:false_type
{};
}//namespace detail
template<
    typename _TI_Constant_1,
    typename _TI_Constant_2,
    typename... _TI_Constant_N
>
struct ConstantAnd
    :detail::ConstantAndHelper<
        typename _TI_Constant_1::type
        ,typename _TI_Constant_2::type
        ,typename _TI_Constant_N::type...
    >
{};
template<
    typename _TI_Constant_1,
    typename _TI_Constant_2,
    typename... _TI_Constant_N
>
using constant_and_t=typename ConstantAnd<
    _TI_Constant_1
    ,_TI_Constant_2
    ,_TI_Constant_N...
>::type;
