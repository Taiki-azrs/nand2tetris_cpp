#include<iostream>
#include<cstdio>
#include<tuple>
#include"word.hpp"
#include"gate.hpp"
#include"adder.hpp"
void test_half_adder(){
  std::cout << "===half adder===" << std::endl;
  for(int i=0;i<4;i++){
    bool a=(i&0b1);
    bool b=(i&0b10)>>1;
    auto ans=adder::half_adder(a,b);
    std::cout <<"half_adder("<<a<<","<<b<<")= ("<<std::get<0>(ans) <<"," <<std::get<1>(ans)<<")"<<std::endl;
  }  
}
void test_full_adder(){
  std::cout << "===full adder===" << std::endl;
  for(int i=0;i<8;i++){
    bool a=(i&0b1);
    bool b=(i&0b10)>>1;
    bool c=(i&0b100)>>2;
    auto ans=adder::full_adder(a,b,c);
    std::cout <<"half_adder("<<a<<","<<b<<","<<c<<")= ("<<std::get<0>(ans) <<"," <<std::get<1>(ans)<<")"<<std::endl;
  }  
}
void test_add16(){
  std::cout << "===add16===" << std::endl;
  word a;
  word b;
  for(int i=0;i<WORD_SIZE;i++){
    a.set(i,i%2);
    if(i<8){
      b.set(i,1);
    }else{
      b.set(i,0);
    }
  }
  word c=adder::add16(a,b);
  a.print();
  std::cout << "+"<<std::endl;
  b.print();
  std::cout<<""<<std::endl;
  c.print();
}
void test_inc16(){
  std::cout << "===inc16===" << std::endl;
  word a;
  for(int i=0;i<WORD_SIZE;i++){
    a.set(i,i%2);
  }
  word c=adder::inc16(a);
  a.print();
  std::cout <<"+"<<std::endl;
  std::cout<<"1"<<std::endl;
  c.print();
}
int main(){
  test_half_adder();
  test_full_adder();
  test_add16();
  test_inc16();
  return 0;
}
