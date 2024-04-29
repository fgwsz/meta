#pragma once
template<typename _Type>
struct RemoveLValueReference{
    using type=_Type;
};
template<typename _Type>
struct RemoveLValueReference<_Type&>{
    using type=_Type;
};
template<typename _Type>
using remove_lvalue_reference_t=typename RemoveLValueReference<_Type>::type;
