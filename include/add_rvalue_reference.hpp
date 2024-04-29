#pragma once
#include"type_identity.hpp"
namespace detail{
template<typename _Type>//注意“cv void&”是替换失败
auto try_add_rvalue_reference(int)->TypeIdentity<_Type&&>;
template<typename _Type>//处理T=cv void的情况
auto try_add_rvalue_reference(...)->TypeIdentity<_Type>;
}//namespace detail
template<typename _Type>
struct AddRValueReference
    :decltype(detail::try_add_rvalue_reference<_Type>(0))
{};
template<typename _Type>
using add_rvalue_reference_t=typename AddRValueReference<_Type>::type;
