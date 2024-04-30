#pragma once
#include"static_string.hpp"
#include"static_string_find_first_of.hpp"
#include"static_string_find_last_of.hpp"
#include"static_string_find_first_not_of.hpp"
#include"static_string_find_last_not_of.hpp"
#include"static_string_substr.hpp"
template<typename _Type>
consteval auto type_name()noexcept{
// gcc||clang||msvc with clang||mingw
#if defined(__GUNC__)||defined(__clang__)|| \
    defined(__MINGW32__)||defined(__MINGW64__)
    using function_name=StaticString<__PRETTY_FUNCTION__>;
    using front_index_1=Constant<size_type,
        static_string_find_first_of_v<function_name,'='>+1>;
    using back_index_1=Constant<size_type,
        static_string_find_last_of_v<function_name,']'>-1>;
// msvc without clang
#elif defined(_MSC_VER)
    using function_name=StaticString<__FUNCSIG__>;
    using front_index_1=Constant<size_type,
        static_string_find_first_of_v<function_name,'<'>+1>;
    using back_index_1=Constant<size_type,
        static_string_find_last_of_v<function_name,'>'>-1>;
#endif
    using front_index_2=Constant<size_type,
        static_string_find_first_not_of_v<function_name,' ',front_index_1::value>>;
    using back_index_2=Constant<size_type,
        static_string_find_last_not_of_v<function_name,' ',back_index_1::value>>;
    return static_string_substr_t<
        function_name,
        front_index_2::value,
        back_index_2::value-front_index_2::value+1
    >{};
}
template<typename _Type>
using type_name_t=decltype(type_name<_Type>());
