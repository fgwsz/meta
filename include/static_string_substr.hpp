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
    using type=decltype(
        detail::static_string_substr<_TI_StaticString,_pos,count>()
    );
};
template<
    typename _TI_StaticString,
    size_type _pos=0,
    size_type _count=size_type_inf
>
using static_string_substr_t=
    typename StaticStringSubstr<_TI_StaticString,_pos,_count>::type;
