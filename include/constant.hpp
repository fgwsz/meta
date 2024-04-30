#pragma once
template<typename _Type,_Type _value>
struct Constant{
    using type=Constant<_Type,_value>;
    using value_type=_Type;
    static constexpr value_type value=_value;
    constexpr operator value_type(void)const noexcept{
        return _value;
    }
    constexpr value_type operator()(void)const noexcept{
        return _value;
    }
};
