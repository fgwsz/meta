#pragma once
#include"bool_constant.hpp"
#include"remove_cv.hpp"
template<typename _Type>
struct IsMemberPointerHelper
    :false_type
{};
template<typename _ClassType,typename _MemberType>
struct IsMemberPointerHelper
    <_MemberType _ClassType::*>:true_type
{};
template<typename _Type>
struct IsMemberPointer
    :IsMemberPointerHelper<remove_cv_t<_Type>>
{};
template<typename _Type>
static constexpr bool is_member_pointer_v=IsMemberPointer<_Type>::value;
