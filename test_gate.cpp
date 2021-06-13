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
    std::cout << "dmux("<<x[0]<<","<<x[1]<<")="<<ans[0] <<","<<ans[1]<<std::endl;
#endif
    if(ans[0]!=(bool)x[2] || ans[1]!=(bool)x[3])return -1;
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

int test_mux4way16(){
  word a,b,c,d;
  int16_t sel;
  auto inp=input_cmp((char*)"cmp/Mux4Way16.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    a.set_word(x[0]);
    b.set_word(x[1]);
    c.set_word(x[2]);
    d.set_word(x[3]);
    sel=x[4];
    auto out=gate::_mux4way16(a,b,c,d,sel);
    if(out.get_word()!=(int16_t)x[5])return -1;
    #ifdef DEBUG
    std::cout<<"mux4way16:"<<std::bitset<16>(x[0])<<","<<std::bitset<16>(x[1])<<","<<std::bitset<16>(x[2])
	     <<","<<std::bitset<16>(x[3])<<std::bitset<2>(x[4])
	     <<"="<<std::bitset<16>(out.get_word())<<std::endl;
    #endif
  }
  return 0;
}

int test_mux8way16(){
  word a,b,c,d,e,f,g,h;
  int16_t sel;
  auto inp=input_cmp((char*)"cmp/Mux8Way16.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    a.set_word(x[0]);
    b.set_word(x[1]);
    c.set_word(x[2]);
    d.set_word(x[3]);
    e.set_word(x[4]);
    f.set_word(x[5]);
    g.set_word(x[6]);
    h.set_word(x[7]);
    sel=x[8];
    auto out=gate::_mux8way16(a,b,c,d,e,f,g,h,sel);
    if(out.get_word()!=(int16_t)x[9])return -1;
    #ifdef DEBUG
    std::cout<<"mux8way16:"<<std::bitset<16>(x[0])<<","<<std::bitset<16>(x[1])<<","<<std::bitset<16>(x[2])
	     <<","<<std::bitset<16>(x[3])<<","<<std::bitset<2>(x[4])<<","<<std::bitset<16>(x[5])
	     <<","<<std::bitset<16>(x[6])<<","<<std::bitset<16>(x[7])<<","<<std::bitset<2>(x[8])
	     <<"="<<std::bitset<16>(out.get_word())<<std::endl;
    #endif
  }
  return 0;
}

int test_dmux4way(){
  auto inp=input_cmp((char*)"cmp/DMux4Way.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    auto ans = gate::_dmux4way((bool)x[0],x[1]);
#ifdef DEBUG
    std::cout << "dmux4way("<<x[0]<<","<<x[1]<<")="<<ans[0]<<","<<ans[1]
	      <<","<<ans[2]<<","<<ans[3]<<std::endl;
#endif
    if(ans[0]!=(bool)x[2] || ans[1]!=(bool)x[3] || ans[2]!=(bool)x[4] || ans[3]!=(bool)x[5] )return -1;
  }
  return 0;
}
int test_dmux8way(){
  auto inp=input_cmp((char*)"cmp/DMux8Way.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    auto ans = gate::_dmux8way((bool)x[0],x[1]);
#ifdef DEBUG
    std::cout << "dmux8way("<<x[0]<<","<<x[1]<<")=(";
    for(int i=0;i<8;i++){
      std::cout<<ans[i]<<",";
    }
    std::cout<<")"<<std::endl;
#endif
    if(ans[0]!=(bool)x[2] || ans[1]!=(bool)x[3] || ans[2]!=(bool)x[4] || ans[3]!=(bool)x[5] ||
       ans[4]!=(bool)x[6] || ans[5]!=(bool)x[7] || ans[6]!=(bool)x[8] || ans[7]!=(bool)x[9])return -1;
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
  if(test_mux4way16()==-1)return -1;
  if(test_mux8way16()==-1)return -1;
  if(test_dmux4way()==-1)return -1;
  if(test_dmux8way()==-1)return -1;
  return 0;
}
