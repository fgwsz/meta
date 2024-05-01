#pragma once
#include"constant.hpp"
namespace detail{
// decl
template<
    typename _TI_Constant_1
    ,typename... _TI_Constant_N
>
struct ConstantSubHelper;
// impl 1
template<typename _TI_Constant_1>
struct ConstantSubHelper
    <_TI_Constant_1>{
    using type=_TI_Constant_1;
};
// impl 2
template<
    typename _TI_Constant_1
    ,typename _TI_Constant_2
    ,typename... _TI_Constant_N
>
struct ConstantSubHelper
    <_TI_Constant_1,_TI_Constant_2,_TI_Constant_N...>{
private:
    static constexpr auto value=
        _TI_Constant_1::type::value-_TI_Constant_2::type::value;
    using value_type=decltype(value);
    using current_result=Constant<value_type,value>;
public:
    using type=typename ConstantSubHelper<
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
struct ConstantSub{
    using type=typename detail::ConstantSubHelper<
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
using constant_sub_t=typename ConstantSub<
    _TI_Constant_1
    ,_TI_Constant_2
    ,_TI_Constant_N...
>::type;
