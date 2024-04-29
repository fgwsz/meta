#pragma once
#include"sequence.hpp"
#include"constant.hpp"
template<typename _TI_Sequence,typename _TI_Constant>
struct SequencePushBack;
template<typename _Type,_Type... _values,_Type _value>
struct SequencePushBack
    <Sequence<_Type,_values...>,Constant<_Type,_value>>{
    using type=Sequence<_Type,_values...,_value>;
};
template<typename _TI_Sequence,typename _TI_Constant>
using sequence_push_back_t=
    typename SequencePushBack<_TI_Sequence,_TI_Constant>::type;
