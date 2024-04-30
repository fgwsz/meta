#pragma once
#include"static_string.hpp"
#include"sequence.hpp"
#include"make_index_sequence.hpp"
namespace detail{
template<typename _TI_StaticString,typename _TI_index_sequence>
struct StaticStringToSequenceHelper;
template<typename _TI_StaticString,size_type... _indexs>
struct StaticStringToSequenceHelper
    <_TI_StaticString,Sequence<size_type,_indexs...>>{
    using type=Sequence<
        typename _TI_StaticString::char_type,
        _TI_StaticString::value[_indexs]...
    >;
};
}//namespace detail
template<typename _TI_StaticString>
struct StaticStringToSequence{
    using type=typename detail::StaticStringToSequenceHelper<
        _TI_StaticString,
        make_index_sequence_t<_TI_StaticString::length>
    >::type;
};
template<typename _TI_StaticString>
using static_string_to_sequence_t=
    typename StaticStringToSequence<_TI_StaticString>::type;
