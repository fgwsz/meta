#pragma once
#include"bool_constant.hpp"
#include"is_function.hpp"
#include"remove_cv.hpp"
template<typename _Type>
struct IsMemberFunctionPointerHelper
    :false_type
{};
template<typename _ClassType,typename _MemberType>
struct IsMemberFunctionPointerHelper
    <_MemberType _ClassType::*>:IsFunction<_MemberType>
{};
template<typename _Type>
struct IsMemberFunctionPointer
    :IsMemberFunctionPointerHelper<remove_cv_t<_Type>>
{};
template<typename _Type>
static constexpr bool is_member_function_pointer_v=
    IsMemberFunctionPointer<_Type>::value;
