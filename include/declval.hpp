#pragma once
#include"add_rvalue_reference.hpp"
template<typename _Type>
consteval add_rvalue_reference_t<_Type> declval()noexcept;
