#pragma once
template<typename _Type>
struct RemoveCV{
    using type=_Type;
};
template<typename _Type>
struct RemoveCV<_Type const>{
    using type=_Type;
};
template<typename _Type>
struct RemoveCV<_Type volatile>{
    using type=_Type;
};
template<typename _Type>
struct RemoveCV<_Type const volatile>{
    using type=_Type;
};
template<typename _Type>
using remove_cv_t=typename RemoveCV<_Type>::type;
