#pragma once
#include"remove_reference.hpp"
#include"is_lvalue_reference.hpp"
template<typename _Type>
static constexpr _Type&&
forward(remove_reference_t<_Type>& lvalue_reference)noexcept{
    return static_cast<_Type&&>(lvalue_reference);
}
template<typename _Type>
static constexpr _Type&&
forward(remove_reference_t<_Type>&& rvalue_reference)noexcept{
    static_assert(!is_lvalue_reference_v<_Type>,
    "forward must not be used to convert an rvalue to an lvalue");
    return static_cast<_Type&&>(rvalue_reference);
}
