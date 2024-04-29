#pragma once
template<typename _Type>
struct RemoveReference{
    using type=_Type;
};
template<typename _Type>
struct RemoveReference<_Type&>{
    using type=_Type;
};
template<typename _Type>
struct RemoveReference<_Type&&>{
    using type=_Type;
};
template<typename _Type>
using remove_reference_t=typename RemoveReference<_Type>::type;
