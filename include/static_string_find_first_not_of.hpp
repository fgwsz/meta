#pragma once
#include"size_type.hpp"
#include"static_string.hpp"
template<typename _TI_StaticString,typename _TI_StaticString::char_type _value,size_type _pos=0>
static consteval size_type static_string_find_first_not_of(void)noexcept{
    for(size_type index=_pos;index<_TI_StaticString::length;++index){
        if(_TI_StaticString::value[index]!=_value){
            return index;
        }
    }
    return size_type_inf;
}
template<typename _TI_StaticString,typename _TI_StaticString::char_type _value,size_type _pos=0>
static constexpr size_type static_string_find_first_not_of_v=
    static_string_find_first_not_of<_TI_StaticString,_value,_pos>();