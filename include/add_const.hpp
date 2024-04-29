#pragma once
template<typename _Type>
struct AddConst{
    using type=_Type const;
};
template<typename _Type>
using add_const_t=typename AddConst<_Type>::type;
