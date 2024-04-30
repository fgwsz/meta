#pragma once
#include"constant.hpp"
template<typename _TI_Constant_1,typename _TI_Constant_2>
struct Constant_Max;
template<typename _Type,_Type _value_1,_Type _value_2>
struct Constant_Max<Constant<_Type,_value_1>,Constant<_Type,_value_2>>{
private:
    static constexpr _Type value=_value_1>_value_2?_value_1:_value_2;
public:
    using type=Constant<_Type,value>;
};
template<typename _TI_Constant_1,typename _TI_Constant_2>
using constant_max_t=typename Constant_Max<_TI_Constant_1,_TI_Constant_2>::type;