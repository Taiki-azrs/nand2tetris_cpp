#include<iostream>
#include<cstdio>
#include<tuple>
#include"word.hpp"
#include"gate.hpp"
void test_nand(){
  std::cout << "===nand gate===" << std::endl;
  std::cout <<"nand(1,1)=" << gate::_nand(1,1)<<std::endl;
  std::cout <<"nand(0,1)=" <<gate::_nand(0,1)<<std::endl;
  std::cout <<"nand(1,0)=" <<gate::_nand(1,0)<<std::endl;
  std::cout <<"nand(0,0)=" <<gate::_nand(0,0)<<std::endl;
}
void test_not(){
  std::cout << "===not gate===" << std::endl;
  std::cout <<"not(1)=" << gate::_not(1)<<std::endl;
  std::cout <<"not(0)=" <<gate::_not(0)<<std::endl;
}
void test_and(){
  std::cout << "===and gate===" << std::endl;
  std::cout <<"and(1,1)=" << gate::_and(1,1)<<std::endl;
  std::cout <<"and(0,1)=" <<gate::_and(0,1)<<std::endl;
  std::cout <<"and(1,0)=" <<gate::_and(1,0)<<std::endl;
  std::cout <<"and(0,0)=" <<gate::_and(0,0)<<std::endl;
}
void test_or(){
  std::cout << "===or gate===" << std::endl;
  std::cout <<"or(1,1)=" << gate::_or(1,1)<<std::endl;
  std::cout <<"or(0,1)=" <<gate::_or(0,1)<<std::endl;
  std::cout <<"or(1,0)=" <<gate::_or(1,0)<<std::endl;
  std::cout <<"or(0,0)=" <<gate::_or(0,0)<<std::endl;
}
void test_xor(){
  std::cout << "===xor gate===" << std::endl;
  std::cout <<"xor(1,1)=" << gate::_xor(1,1)<<std::endl;
  std::cout <<"xor(0,1)=" <<gate::_xor(0,1)<<std::endl;
  std::cout <<"xor(1,0)=" <<gate::_xor(1,0)<<std::endl;
  std::cout <<"xor(0,0)=" <<gate::_xor(0,0)<<std::endl;  
}
void test_mux(){
  std::cout << "===mux gate===" << std::endl;
  for(int i=0;i<8;i++){
    bool a=(i&0b1);
    bool b=(i&0b10)>>1;
    bool sel=(i&100)>>2;
    std::cout <<"mux("<<a<<","<<b<<","<<sel<<")=" << gate::_mux(a,b,sel)<<std::endl;
  }  
}
void test_dmux(){
  std::cout << "===dmux(in,sel)===" << std::endl;
  auto ans=gate::_dmux(1,1);
  auto ans2=gate::_dmux(0,1);
  auto ans3=gate::_dmux(1,0);
  auto ans4=gate::_dmux(0,0);
  std::cout <<"dmux(1,1)=" <<std::get<0>(ans) <<","<<std::get<1>(ans) <<std::endl;
  std::cout <<"dmux(0,1)=" <<std::get<0>(ans2) <<","<<std::get<1>(ans2) <<std::endl;
  std::cout <<"dmux(1,0)=" <<std::get<0>(ans3) <<","<<std::get<1>(ans3) <<std::endl;
  std::cout <<"dmux(0,0)=" <<std::get<0>(ans4) <<","<<std::get<1>(ans4) <<std::endl;
}
void test_and16(){
  std::cout << "===and16===" << std::endl;
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
  word c=gate::_and16(a,b);
  a.print();
  std::cout << "and"<<std::endl;
  b.print();
  std::cout<<""<<std::endl;
  c.print();
}
void test_or16(){
  std::cout << "===or16===" << std::endl;
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
  word c=gate::_or16(a,b);
  a.print();
  std::cout << "or"<<std::endl;
  b.print();
  std::cout<<""<<std::endl;
  c.print();
}
void test_not16(){
  std::cout << "===not16===" << std::endl;
  word a;
  for(int i=0;i<WORD_SIZE;i++){
    a.set(i,i%2);
  }
  word c=gate::_not16(a);
  std::cout << "not"<<std::endl;
  a.print();
  std::cout<<""<<std::endl;
  c.print();
}
void test_mux16(){
  std::cout << "===mux16===" << std::endl;
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
  word c=gate::_mux16(a,b,0);
  a.print();
  std::cout << "or"<<std::endl;
  b.print();
  std::cout<<"sel=0"<<std::endl;
  c.print();
  c=gate::_mux16(a,b,1);
  std::cout<<"sel=1"<<std::endl;
  c.print();
}

int main(){
  test_and16();
  test_or16();
  test_not16();
  test_mux16();
  return 0;
}
