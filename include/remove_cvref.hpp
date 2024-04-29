#pragma once
#include"remove_cv.hpp"
#include"remove_reference.hpp"
template<typename _Type>
struct RemoveCVRef{
    using type=remove_cv_t<remove_reference_t<_Type>>;
};
template<typename _Type>
using remove_cvref_t=typename RemoveCVRef<_Type>::type;
