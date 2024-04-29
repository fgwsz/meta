#pragma once
template<typename _Type>
struct RemoveVolatile{
    using type=_Type;
};
template<typename _Type>
struct RemoveVolatile<_Type volatile>{
    using type=_Type;
};
template<typename _Type>
using remove_volatile_t=typename RemoveVolatile<_Type>::type;
