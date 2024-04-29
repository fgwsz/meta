#pragma once
#include"remove_reference.hpp"
template<typename _Type>
static constexpr remove_reference_t<_Type>&&
move(_Type&& reference)noexcept{
    return static_cast<remove_reference_t<_Type>&&>(reference);
}