#pragma once
#include"size_type.hpp"
template<typename _Type>
struct RemoveExtent{
    using type=_Type;
};
template<typename _Type>
struct RemoveExtent<_Type[]>{
    using type=_Type;
};
template<typename _Type,size_type _size>
struct RemoveExtent<_Type[_size]>{
    using type=_Type;
};
template<typename _Type>
using remove_extent_t=typename RemoveExtent<_Type>::type;
