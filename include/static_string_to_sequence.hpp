#pragma once
#include"static_string.hpp"
#include"index_sequence.hpp"
#include"sequence.hpp"
#include"declval.hpp"
#include"make_index_sequence.hpp"
namespace detail{
template<
    typename _TI_StaticString,
    size_type... _indexs
>
static consteval auto __static_string_to_sequence(
    index_sequence<_indexs...>&&
){
    return Sequence<
        typename _TI_StaticString::char_type,
        _TI_StaticString::value[_indexs]...
    >{};
}
template<typename _TI_StaticString>
static consteval auto static_string_to_sequence()
->decltype(__static_string_to_sequence<_TI_StaticString>(
    declval<make_index_sequence_t<_TI_StaticString::length>>()
));
}//namespace detail
template<typename _TI_StaticString>
using static_string_to_sequence_t=
    decltype(detail::static_string_to_sequence<_TI_StaticString>());
