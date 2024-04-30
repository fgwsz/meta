#pragma once
#include"size_type.hpp"
namespace detail{
template<typename _CharType,size_type _size>
struct CStr{
    _CharType value[_size];
    consteval CStr(_CharType const(&c_str)[_size])noexcept{
        for(size_type index=0;index<_size;++index){
            this->value[index]=c_str[index];
        }
    }
    using char_type=_CharType;
    static constexpr size_type size=_size;
    static constexpr size_type length=_size-1;
};
}//namespace detail
template<detail::CStr _c_str>
struct StaticString{
    using value_type=decltype((_c_str.value));
    static constexpr value_type value=(_c_str.value);
    using char_type=typename decltype(_c_str)::char_type;
    static constexpr size_type size=_c_str.size;
    static constexpr size_type length=_c_str.length;
    constexpr operator value_type(void)const noexcept{
        return this->value;
    }
    constexpr value_type operator()(void)const noexcept{
        return this->value;
    }
};
