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
    return 0;
}
