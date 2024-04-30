#pragma once
#include"size_type.hpp"
#include"static_string.hpp"
#include"constant_min.hpp"
template<typename _TI_StaticString,typename _TI_StaticString::char_type _value,size_type _pos=size_type_inf>
static consteval size_type static_string_find_last_of(void)noexcept{
    if constexpr(_TI_StaticString::length==0){
        return size_type_inf;
    }else{
        using pos=constant_min_t<
            Constant<size_type,_pos>,
            Constant<size_type,_TI_StaticString::length-1>
        >;
        for(size_type index=pos::value;;--index){
            if(_TI_StaticString::value[index]==_value){
                return index;
            }
            if(index==0){
                break;
            }
        }
        return size_type_inf;
    }
}
template<typename _TI_StaticString,typename _TI_StaticString::char_type _value,size_type _pos=size_type_inf>
static constexpr size_type static_string_find_last_of_v=
    static_string_find_last_of<_TI_StaticString,_value,_pos>();