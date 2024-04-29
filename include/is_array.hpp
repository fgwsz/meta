#pragma once
#include"bool_constant.hpp"
#include"size_type.hpp"
template<typename _Type>
struct IsArray
    :false_type
{};
template<typename _Type>
struct IsArray
    <_Type[]>:true_type
{};
template<typename _Type,size_type _size>
struct IsArray
    <_Type[_size]>:true_type
{};
template<typename _Type>
static constexpr bool is_array_v=IsArray<_Type>::value;
