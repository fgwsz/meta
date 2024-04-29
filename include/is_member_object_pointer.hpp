#pragma once
#include"bool_constant.hpp"
#include"is_member_pointer.hpp"
#include"is_member_function_pointer.hpp"
template<typename _Type>
struct IsMemberObjectPointer
    :bool_constant<
        is_member_pointer_v<_Type>
        &&!is_member_function_pointer_v<_Type>
    >
{};
template<typename _Type>
static constexpr bool is_member_object_pointer_v=
    IsMemberObjectPointer<_Type>::value;
