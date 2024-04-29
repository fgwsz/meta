#pragma once
template<typename _Type>
struct RemovePointer{
    using type=_Type;
};
template<typename _Type>
struct RemovePointer<_Type*>{
    using type=_Type;
};
template<typename _Type>
struct RemovePointer<_Type* const>{
    using type=_Type;
};
template<typename _Type>
struct RemovePointer<_Type* volatile>{
    using type=_Type;
};
template<typename _Type>
struct RemovePointer<_Type* const volatile>{
    using type=_Type;
};
template<typename _Type>
using remove_pointer_t=typename RemovePointer<_Type>::type;
