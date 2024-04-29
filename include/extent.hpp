#pragma once
#include"constant.hpp"
#include"size_type.hpp"
template<typename _Type,size_type _rank_index=0>
struct Extent
    :Constant<size_type,0>
{};
template<typename _Type>
struct Extent
    <_Type[],0>:Constant<size_type,0>
{};
template<typename _Type,size_type _rank_index>
struct Extent
    <_Type[],_rank_index>:Extent<_Type,_rank_index-1>
{};
template<typename _Type,size_type _size>
struct Extent
    <_Type[_size],0>:Constant<size_type,_size>
{};
template<typename _Type,size_type _size,size_type _rank_index>
struct Extent
    <_Type[_size],_rank_index>:Extent<_Type,_rank_index-1>
{};
template<typename _Type,size_type _rank_index=0>
static constexpr size_type extent_v=Extent<_Type,_rank_index>::value;
