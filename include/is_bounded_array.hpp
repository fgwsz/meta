#pragma once
#include"bool_constant.hpp"
#include"size_type.hpp"
template<typename _Type>
struct IsBoundedArray
    :false_type
{};
template<typename _Type,size_type _size>
struct IsBoundedArray
    <_Type[_size]>:true_type
{};
template<typename _Type>
static constexpr bool is_bounded_array_v=IsBoundedArray<_Type>::value;
