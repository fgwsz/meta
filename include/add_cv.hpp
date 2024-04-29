#pragma once
template<typename _Type>
struct AddCV{
    using type=_Type const volatile;
};
template<typename _Type>
using add_cv_t=typename AddCV<_Type>::type;
