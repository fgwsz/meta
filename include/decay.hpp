#pragma once
#include"remove_reference.hpp"
#include"conditional.hpp"
#include"is_array.hpp"
#include"add_pointer.hpp"
#include"remove_extent.hpp"
#include"is_function.hpp"
#include"remove_cv.hpp"
template<typename _Type>
struct Decay{
private:
    using base_type=remove_reference_t<_Type>;
public:
    using type=conditional_t<
        is_array_v<base_type>,
        add_pointer_t<remove_extent_t<base_type>>,
        conditional_t<
            is_function_v<base_type>,
            add_pointer_t<base_type>,
            remove_cv_t<base_type>
        >
    >;
};
template<typename _Type>
using decay_t=typename Decay<_Type>::type;
