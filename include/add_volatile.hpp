#pragma once
template<typename _Type>
struct AddVolatile{
    using type=_Type volatile;
};
template<typename _Type>
using add_volatile_t=typename AddVolatile<_Type>::type;
