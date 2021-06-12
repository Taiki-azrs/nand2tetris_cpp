#include<iostream>
#include<cstdio>
#include<tuple>
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
    //std::cout<<"and("<<x[0]<<","<<x[1]<<")="<<ans<<std::endl;
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
    //std::cout<<"or("<<x[0]<<","<<x[1]<<")="<<ans<<std::endl;
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
    //std::cout<<"xor("<<x[0]<<","<<x[1]<<")="<<ans<<std::endl;
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
    //std::cout <<"mux("<<x[0]<<","<<x[1]<<","<<x[2]<<")=" << ans<<std::endl;
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
    std::cout << "dmux("<<x[0]<<","<<x[1]<<")="<<std::get<0>(ans) <<","<<std::get<1>(ans)<<std::endl;
    if(std::get<0>(ans)!=(bool)x[2] || std::get<1>(ans)!=(bool)x[3])return -1;
  }
  return 0;
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
  if(test_not()==-1)return -1;
  if(test_and()==-1)return -1;
  if(test_or()==-1)return -1;
  if(test_xor()==-1)return -1;
  if(test_mux()==-1)return -1;
  if(test_dmux()==-1)return -1;  
  // test_and16();
  // test_or16();
  // test_not16();
  // test_mux16();
  return 0;
}
