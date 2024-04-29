#pragma once
#include"constant.hpp"
#include"size_type.hpp"
template<typename _Type>
struct Rank
    :Constant<size_type,0>
{};
template<typename _Type>
struct Rank
    <_Type[]>:Constant<size_type,Rank<_Type>::value+1>
{};
template<typename _Type,size_type _size>
struct Rank
    <_Type[_size]>:Constant<size_type,Rank<_Type>::value+1>
{};
template<typename _Type>
static constexpr size_type rank_v=Rank<_Type>::value;
