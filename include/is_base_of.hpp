#pragma once
#include"bool_constant.hpp"
namespace detail{
template<typename _From,typename _To>
struct Conversion{
private:
    struct Big{
        char dummy[2];
    };
    using small=char;
    using big=Big;
    static small test(_To);
    static big test(...);
    static _From make_from();
public:
    static constexpr bool exists=
        sizeof(test(make_from()))==sizeof(small);
    static constexpr bool exists_2_way=
        exists
        &&Conversion<_To,_From>::exists;
    static constexpr bool same=
        false;
};
template<typename _Type>
struct Conversion
    <_Type,_Type>{
    static constexpr bool exists=true;
    static constexpr bool exists_2_way=true;
    static constexpr bool same=true;
};
}//namespace detail
template<typename _Base,typename _Derived>
struct IsBaseOf
    :bool_constant<
        (
            detail::Conversion<_Derived const*,_Base const*>::exists
            &&!detail::Conversion<_Base const*,void const*>::exists
        )
        &&!detail::Conversion<_Base const,_Derived const>::same
    >
{};
template<typename _Base,typename _Derived>
static constexpr bool is_base_of_v=IsBaseOf<_Base,_Derived>::value;
