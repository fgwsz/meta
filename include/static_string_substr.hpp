#pragma once
#include"size_type.hpp"
#include"static_string.hpp"
#include"sequence.hpp"
#include"index_sequence_plus_offset.hpp"
#include"make_index_sequence.hpp"
namespace detail{
template<typename _TI_StaticString,typename _TI_index_sequence>
struct StaticStringSubstrHelper;
template<typename _TI_StaticString,size_type... _indexs>
struct StaticStringSubstrHelper
    <_TI_StaticString,Sequence<size_type,_indexs...>>{
    using type=StaticString<
        detail::CStr({
            _TI_StaticString::value[_indexs]...,
            typename _TI_StaticString::char_type{'\0'}
        })
    >;
};
}//namespace detail
template<
    typename _TI_StaticString,
    size_type _pos=0,
    size_type _count=size_type_inf
>
struct StaticStringSubstr{
private:
    static constexpr bool check_pos=_pos<_TI_StaticString::length;
    static constexpr size_type count=
        (!check_pos)
            ?0
            :(_count>(_TI_StaticString::length-_pos)
                    ?(_TI_StaticString::length-_pos)
                    :_count);
public:
    using type=typename detail::StaticStringSubstrHelper<
        _TI_StaticString,
        index_sequence_plus_offset_t<
            make_index_sequence_t<count>,
            _pos
        >
    >::type;
};
template<
    typename _TI_StaticString,
    size_type _pos=0,
    size_type _count=size_type_inf
>
using static_string_substr_t=
    typename StaticStringSubstr<_TI_StaticString,_pos,_count>::type;
