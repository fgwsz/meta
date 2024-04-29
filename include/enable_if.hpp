#pragma once
template<bool _expr,typename _Type=void>
struct EnableIf{};
template<typename _Type>
struct EnableIf<true,_Type>{
    using type=_Type;
};
template<bool _expr,typename _Type=void>
using enable_if_t=typename EnableIf<_expr,_Type>::type;
