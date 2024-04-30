#include<iostream>
#include"meta.hpp"
int main(int argc,char* argv[]){
    using static_string=StaticString<"hello meta!">;
    using char_sequence=static_string_to_sequence_t<static_string>;
    ::std::cout<<typename_t<static_string>{}.value<<"\n";
    ::std::cout<<typename_t<char_sequence>{}.value<<"\n";
    return 0;
}
