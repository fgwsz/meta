#pragma once
#include"size_type.hpp"
#include"index_sequence.hpp"
#include"sequence_push_back.hpp"
#include"constant.hpp"
template<size_type _size>
struct MakeIndexSequence;
template<>
struct MakeIndexSequence<0>{
    using type=index_sequence<>;
};
template<size_type _size>
struct MakeIndexSequence{
    using type=sequence_push_back_t<
        typename MakeIndexSequence<_size-1>::type,
        Constant<size_type,_size-1>
    >;
};
template<size_type _size>
using make_index_sequence_t=typename MakeIndexSequence<_size>::type;
