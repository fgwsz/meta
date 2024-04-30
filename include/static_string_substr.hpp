#pragma once
#include"size_type.hpp"
#include"static_string.hpp"
#include"index_sequence_plus_offset.hpp"
#include"make_index_sequence.hpp"
namespace detail{
template<typename _TI_StaticString,size_type... _indexs>
static consteval auto static_string_substr_helper(
    Sequence<size_type,_indexs...>&&
)noexcept
->StaticString<
    detail::CStr({
        _TI_StaticString::value[_indexs]...,
        typename _TI_StaticString::char_type{'\0'}
    })
>;
template<typename _TI_StaticString,size_type _pos,size_type _count>
static consteval auto static_string_substr(void)noexcept
->decltype(
    static_string_substr_helper<_TI_StaticString>(
        declval<
            index_sequence_plus_offset_t<
                make_index_sequence_t<_count>,
                _pos
            >
        >()
    )
);
}//namespace detail
template<typename _TI_StaticString,size_type _pos,size_type _count>
using static_string_substr_t=
    decltype(detail::static_string_substr<_TI_StaticString,_pos,_count>());
