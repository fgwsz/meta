#pragma once
template<typename _Type>
struct RemoveConst{
    using type=_Type;
};
template<typename _Type>
struct RemoveConst<_Type const>{
    using type=_Type;
};
template<typename _Type>
using remove_const_t=typename RemoveConst<_Type>::type;
