#pragma once
#include"type_identity.hpp"
namespace detail{
template<typename _Type>
auto try_add_pointer(int)->TypeIdentity<_Type*>;
template<typename _Type>
auto try_add_pointer(...)->TypeIdentity<_Type>;
}//namespace detail
template<typename _Type>
struct AddPointer
    :decltype(detail::try_add_pointer<_Type>(0))
{};
template<typename _Type>
using add_pointer_t=typename AddPointer<_Type>::type;
