#pragma once
#include"size_type.hpp"
template<typename _Type,_Type... _values>
struct Sequence{
    using value_type=_Type;
    static constexpr size_type size()noexcept{
        return sizeof...(_values);
    }
};
