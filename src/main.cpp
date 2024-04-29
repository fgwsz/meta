#include<iostream>
#include"meta.hpp"
using e1=typename IsAbsolutelySame<int,int const>::type;
using e2=typename IsSame<int,int const>::type;
using idxs=make_index_sequence_t<20>;
int main(int argc,char* argv[]){
    ::std::cout<<type_name<idxs>()<<"\n";
    return 0;
}
