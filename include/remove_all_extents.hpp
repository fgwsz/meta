#pragma once
#include"size_type.hpp"
template<typename _Type>
struct RemoveAllExtents{
    using type=_Type;
};
template<typename _Type>
struct RemoveAllExtents<_Type[]>{
    using type=typename RemoveAllExtents<_Type>::type;
};
template<typename _Type,size_type _size>
struct RemoveAllExtents<_Type[_size]>{
    using type=typename RemoveAllExtents<_Type>::type;
};
template<typename _Type>
using remove_all_extents_t=typename RemoveAllExtents<_Type>::type;
