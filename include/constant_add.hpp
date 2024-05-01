#pragma once
#include"constant.hpp"
namespace detail{
// decl
template<
    typename _TI_Constant_1
    ,typename... _TI_Constant_N
>
struct ConstantAddHelper;
// impl 1
template<typename _TI_Constant_1>
struct ConstantAddHelper
    <_TI_Constant_1>{
    using type=_TI_Constant_1;
};
// impl 2
template<
    typename _TI_Constant_1
    ,typename _TI_Constant_2
    ,typename... _TI_Constant_N
>
struct ConstantAddHelper
    <_TI_Constant_1,_TI_Constant_2,_TI_Constant_N...>{
private:
    static constexpr auto value=
        _TI_Constant_1::type::value+_TI_Constant_2::type::value;
    using value_type=decltype(value);
    using current_result=Constant<value_type,value>;
public:
    using type=typename ConstantAddHelper<
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
struct ConstantAdd{
    using type=typename detail::ConstantAddHelper<
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
using constant_add_t=typename ConstantAdd<
    _TI_Constant_1
    ,_TI_Constant_2
    ,_TI_Constant_N...
>::type;
