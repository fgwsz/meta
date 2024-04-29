#pragma once
#include"conjunction.hpp"
#include"is_void.hpp"
#include"declval.hpp"
#include"bool_constant.hpp"
template<typename _From, typename _To>
struct IsNothrowConvertible
    :Conjunction<IsVoid<_From>,IsVoid<_To>>
{};
template<typename _From, typename _To>
requires requires{
    static_cast<_To(*)()>(nullptr);
    {declval<void(&)(_To)noexcept>()(declval<_From>())}noexcept;
}
struct IsNothrowConvertible
    <_From,_To>:true_type
{};
template<typename _From, typename _To>
static constexpr bool is_nothrow_convertible_v=
    IsNothrowConvertible<_From,_To>::value;
