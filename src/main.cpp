#include<iostream>
#include"meta.hpp"
int main(int argc,char* argv[]){
    using static_string=StaticString<"hello meta!">;
    using char_sequence=static_string_to_sequence_t<static_string>;
    ::std::cout<<type_name<static_string>()<<"\n";
    ::std::cout<<type_name<char_sequence>()<<"\n";
    ::std::cout<<type_name<
        static_string_substr_t<StaticString<"01234">>
    >()<<"\n";
    ::std::cout<<type_name<
        static_string_substr_t<StaticString<"01234">,5>
    >()<<"\n";
    ::std::cout<<type_name<
        static_string_substr_t<StaticString<"01234">,5,0>
    >()<<"\n";
    ::std::cout<<type_name<
        static_string_substr_t<StaticString<"01234">,1>
    >()<<"\n";
    ::std::cout<<type_name<
        static_string_substr_t<StaticString<"01234">,1,3>
    >()<<"\n";
    ::std::cout<<
        disjunction_v<
            bool_constant<true>,
            bool_constant<false>,
            Conditional<
                false,
                bool_constant<false>,
                bool_constant<true>
            >
        >
    <<"\n";
    ::std::cout<<
        conjunction_v<bool_constant<true>,bool_constant<false>>
    <<"\n";
    /*
    (ConstEqualTo
        (ConstantOr
            (IsArray int[])
            (IsArray int  ))
        True)
    */
    using namespace scheme;
    ::std::cout<<type_name<typename 
        _<f<ConstantEqualTo>
            ,_<f<ConstantOr>
                ,_<f<IsArray>,t<int[]>>
                ,_<f<IsArray>,t<int>>>
            ,true_type>
    ::type>()<<"\n";
    return 0;
}
/*(IfElse 
    (> number 0)
    number
    (- number))
*/
/*(
    (IfThenElse 
        (> number 0)
        TypeIdentity
        -) 
    number)
*/
using namespace scheme;
template<auto number>
struct Abs:
_<
    _<f<IfThenElse>
        ,_<f<ConstantGreater>,c<number>,c<0>>
        ,f<TypeIdentity>
        ,f<ConstantNegate>>
    ,c<number>>
{};
using abs_of_pi=typename Abs<-3.14>::type;