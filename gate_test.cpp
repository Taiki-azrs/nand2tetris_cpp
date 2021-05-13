#include<iostream>
#include<cstdio>
#include<tuple>
#include"gate.hpp"

int main(){
  std::cout << "===nand gate===" << std::endl;
  std::cout <<"nand(1,1)=" << gate::_nand(1,1)<<std::endl;
  std::cout <<"nand(0,1)=" <<gate::_nand(0,1)<<std::endl;
  std::cout <<"nand(1,0)=" <<gate::_nand(1,0)<<std::endl;
  std::cout <<"nand(0,0)=" <<gate::_nand(0,0)<<std::endl;
  std::cout << "===not gate===" << std::endl;
  std::cout <<"not(1)=" << gate::_not(1)<<std::endl;
  std::cout <<"not(0)=" <<gate::_not(0)<<std::endl;
  std::cout << "===and gate===" << std::endl;
  std::cout <<"and(1,1)=" << gate::_and(1,1)<<std::endl;
  std::cout <<"and(0,1)=" <<gate::_and(0,1)<<std::endl;
  std::cout <<"and(1,0)=" <<gate::_and(1,0)<<std::endl;
  std::cout <<"and(0,0)=" <<gate::_and(0,0)<<std::endl;
  std::cout << "===or gate===" << std::endl;
  std::cout <<"or(1,1)=" << gate::_or(1,1)<<std::endl;
  std::cout <<"or(0,1)=" <<gate::_or(0,1)<<std::endl;
  std::cout <<"or(1,0)=" <<gate::_or(1,0)<<std::endl;
  std::cout <<"or(0,0)=" <<gate::_or(0,0)<<std::endl;
  std::cout << "===xor gate===" << std::endl;
  std::cout <<"xor(1,1)=" << gate::_xor(1,1)<<std::endl;
  std::cout <<"xor(0,1)=" <<gate::_xor(0,1)<<std::endl;
  std::cout <<"xor(1,0)=" <<gate::_xor(1,0)<<std::endl;
  std::cout <<"xor(0,0)=" <<gate::_xor(0,0)<<std::endl;
  std::cout << "===mux gate===" << std::endl;
  for(int i=0;i<8;i++){
    bool a=(i&0b1);
    bool b=(i&0b10)>>1;
    bool sel=(i&100)>>2;
    std::cout <<"mux("<<a<<","<<b<<","<<sel<<")=" << gate::_mux(a,b,sel)<<std::endl;
  }
  std::cout << "===dmux(in,sel)===" << std::endl;
  auto ans=gate::_dmux(1,1);
  auto ans2=gate::_dmux(0,1);
  auto ans3=gate::_dmux(1,0);
  auto ans4=gate::_dmux(0,0);
  std::cout <<"dmux(1,1)=" <<std::get<0>(ans) <<","<<std::get<1>(ans) <<std::endl;
  std::cout <<"dmux(0,1)=" <<std::get<0>(ans2) <<","<<std::get<1>(ans2) <<std::endl;
  std::cout <<"dmux(1,0)=" <<std::get<0>(ans3) <<","<<std::get<1>(ans3) <<std::endl;
  std::cout <<"dmux(0,0)=" <<std::get<0>(ans4) <<","<<std::get<1>(ans4) <<std::endl;
  return 0;
}
