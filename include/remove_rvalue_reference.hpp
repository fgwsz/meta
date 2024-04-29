#pragma once
template<typename _Type>
struct RemoveRValueReference{
    using type=_Type;
};
template<typename _Type>
struct RemoveRValueReference<_Type&&>{
    using type=_Type;
};
template<typename _Type>
using remove_rvalue_reference_t=typename RemoveRValueReference<_Type>::type;
