#include<iostream>
#include"meta.hpp"
using val=typename IsAbsolutelySame<int,int const>::type;
int main(int argc,char* argv[]){
    std::cout<<"hello meta!\n";
    std::cout<<val{}()<<"\n";
    return 0;
}
