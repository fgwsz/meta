#pragma once
#include"bool_constant.hpp"
namespace detail{
// decl
template<typename... _TI_Constant_N>
struct ConstantOrHelper;
// impl 0
template<>
struct ConstantOrHelper
    <>:false_type
{};
// impl 1
template<typename... _TI_Constant_N>
struct ConstantOrHelper
    <false_type,_TI_Constant_N...>
    :ConstantOrHelper<_TI_Constant_N...>
{};
// impl 2
template<typename... _TI_Constant_N>
struct ConstantOrHelper
    <true_type,_TI_Constant_N...>:true_type
{};
}//namespace detail
template<
    typename _TI_Constant_1,
    typename _TI_Constant_2,
    typename... _TI_Constant_N
>
struct ConstantOr
    :detail::ConstantOrHelper<
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
using constant_or_t=typename ConstantOr<
    _TI_Constant_1
    ,_TI_Constant_2
    ,_TI_Constant_N...
>::type;
