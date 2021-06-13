#include<iostream>
#include<cstdio>
#include<tuple>
#include<bitset>
#include"word.hpp"
#include"gate.hpp"
#include"input_cmp.hpp"
int test_not(){
  auto inp=input_cmp((char*)"cmp/Not.cmp");
  if(inp[0][0]==-1){
    return -1;
  }

  for(auto x:inp){    
    bool ans = gate::_not((bool)x[0]);
    if(ans!=(bool)x[1])return -1;
  }
  return 0;
}

int test_and(){
  auto inp=input_cmp((char*)"cmp/And.cmp");
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    bool ans = gate::_and((bool)x[0],(bool)x[1]);
#ifdef DEBUG
    std::cout<<"and("<<x[0]<<","<<x[1]<<")="<<ans<<std::endl;
#endif
    if(ans!=(bool)x[2])return -1;
  }
  return 0;
}

int test_or(){
  auto inp=input_cmp((char*)"cmp/Or.cmp");
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    bool ans = gate::_or((bool)x[0],(bool)x[1]);
#ifdef DEBUG
    std::cout<<"or("<<x[0]<<","<<x[1]<<")="<<ans<<std::endl;
#endif
    if(ans!=(bool)x[2])return -1;
  }
  return 0;
}

int test_xor(){
  auto inp=input_cmp((char*)"cmp/Xor.cmp");
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    bool ans = gate::_xor((bool)x[0],(bool)x[1]);
#ifdef DEBUG
    std::cout<<"xor("<<x[0]<<","<<x[1]<<")="<<ans<<std::endl;
#endif
    if(ans!=(bool)x[2])return -1;
  }
  return 0;
}

int test_mux(){
  auto inp=input_cmp((char*)"cmp/Mux.cmp");
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    bool ans = gate::_mux((bool)x[0],(bool)x[1],(bool)x[2]);
#ifdef DEBUG
    std::cout <<"mux("<<x[0]<<","<<x[1]<<","<<x[2]<<")=" << ans<<std::endl;
#endif
    if(ans!=(bool)x[3])return -1;
    
  }
  return 0;
}

int test_dmux(){
  auto inp=input_cmp((char*)"cmp/DMux.cmp");
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    auto ans = gate::_dmux((bool)x[0],(bool)x[1]);
#ifdef DEBUG
    std::cout << "dmux("<<x[0]<<","<<x[1]<<")="<<std::get<0>(ans) <<","<<std::get<1>(ans)<<std::endl;
#endif
    if(std::get<0>(ans)!=(bool)x[2] || std::get<1>(ans)!=(bool)x[3])return -1;
  }
  return 0;
}

int test_and16(){
  word a,b;
  auto inp=input_cmp((char*)"cmp/And16.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    a.set_word(x[0]);
    b.set_word(x[1]);
    auto out=gate::_and16(a,b);
    if(out.get_word()!=(int16_t)x[2])return -1;
    #ifdef DEBUG
    std::cout<<"and16:"<<std::bitset<16>(x[0])<<","<<std::bitset<16>(x[1])<<"="
	     <<std::bitset<16>(out.get_word())<<std::endl;
    #endif
  }
  return 0;
}

int test_or16(){
  word a,b;
  auto inp=input_cmp((char*)"cmp/Or16.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    a.set_word(x[0]);
    b.set_word(x[1]);
    auto out=gate::_or16(a,b);
    if(out.get_word()!=(int16_t)x[2])return -1;
    #ifdef DEBUG
    std::cout<<"or16:"<<std::bitset<16>(x[0])<<","<<std::bitset<16>(x[1])<<"="
	     <<std::bitset<16>(out.get_word())<<std::endl;
    #endif
  }
  return 0;
}

int test_not16(){
  word a,out;
  auto inp=input_cmp((char*)"cmp/Not16.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    a.set_word(x[0]);
    auto out=gate::_not16(a);
    if(out.get_word()!=(int16_t)x[1])return -1;
    #ifdef DEBUG
    std::cout<<"not16:"<<std::bitset<16>(x[0])<<"="<<std::bitset<16>(out.get_word())<<std::endl;
    #endif
  }
  return 0;
}

int test_mux16(){
  word a,b;
  bool sel;
  auto inp=input_cmp((char*)"cmp/Mux16.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    a.set_word(x[0]);
    b.set_word(x[1]);
    sel=x[2];
    auto out=gate::_mux16(a,b,sel);
    if(out.get_word()!=(int16_t)x[3])return -1;
    #ifdef DEBUG
    std::cout<<"mux16:"<<std::bitset<16>(x[0])<<","<<std::bitset<16>(x[1])<<","<<std::bitset<1>(x[2])
	     <<"="<<std::bitset<16>(out.get_word())<<std::endl;
    #endif
  }
  return 0;
}

int main(){
  if(test_not()==-1)return -1;
  if(test_and()==-1)return -1;
  if(test_or()==-1)return -1;
  if(test_xor()==-1)return -1;
  if(test_mux()==-1)return -1;
  if(test_dmux()==-1)return -1;
  if(test_and16()==-1)return -1;
  if(test_or16()==-1)return -1;
  if(test_not16()==-1)return -1;
  if(test_mux16()==-1)return -1;
  return 0;
}
