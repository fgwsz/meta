#pragma once
#include"size_type.hpp"
#include"sequence.hpp"
template<typename _TI_index_sequence,size_type _offset>
struct IndexSequencePlusOffset;
template<size_type... indexs,size_type _offset>
struct IndexSequencePlusOffset<Sequence<size_type,indexs...>,_offset>{
    using type=Sequence<size_type,(indexs+_offset)...>;
};
template<typename _TI_index_sequence,size_type _offset>
using index_sequence_plus_offset_t=
    typename IndexSequencePlusOffset<_TI_index_sequence,_offset>::type;