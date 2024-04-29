#pragma once
template<typename _Type>
struct TypeIdentity{
    using type=_Type;
};
template<typename _Type>
using type_identity_t=typename TypeIdentity<_Type>::type;
