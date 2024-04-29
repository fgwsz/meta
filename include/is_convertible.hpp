#pragma once
#include"bool_constant.hpp"
#include"declval.hpp"
#include"is_void.hpp"
namespace detail{
template<typename _Type>
auto test_returnable(int)->decltype(
    void(static_cast<_Type(*)()>(nullptr)),true_type{}
);
template<typename>
auto test_returnable(...)->false_type;
template<typename _From, typename _To>
auto test_implicitly_convertible(int)->decltype(
    void(declval<void(&)(_To)>()(declval<_From>())),true_type{}
);
template<typename, typename>
auto test_implicitly_convertible(...)->false_type;
}//namespace detail
template<typename _From, typename _To>
struct IsConvertible
    :bool_constant<
        (
            decltype(detail::test_returnable<_To>(0))::value
            &&decltype(detail::test_implicitly_convertible<_From,_To>(0))::value
        )
        ||(IsVoid<_From>::value&&IsVoid<_To>::value)
    >
{};
template<typename _From, typename _To>
static constexpr bool is_convertible_v=IsConvertible<_From,_To>::value;
