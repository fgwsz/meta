#pragma once
#include"constant.hpp"
namespace detail{
// decl
template<
    typename _TI_Constant_1
    ,typename... _TI_Constant_N
>
struct ConstantAndHelper;
// impl 1
template<typename _TI_Constant_1>
struct ConstantAndHelper
    <_TI_Constant_1>{
    using type=_TI_Constant_1;
};
// impl 2
template<
    typename _TI_Constant_1
    ,typename _TI_Constant_2
    ,typename... _TI_Constant_N
>
struct ConstantAndHelper
    <_TI_Constant_1,_TI_Constant_2,_TI_Constant_N...>{
private:
    static constexpr auto value=
        _TI_Constant_1::type::value&&_TI_Constant_2::type::value;
    using value_type=decltype(value);
    using current_result=Constant<value_type,value>;
public:
    using type=typename ConstantAndHelper<
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
struct ConstantAnd{
    using type=typename detail::ConstantAndHelper<
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
using constant_and_t=typename ConstantAnd<
    _TI_Constant_1
    ,_TI_Constant_2
    ,_TI_Constant_N...
>::type;
