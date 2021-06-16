#include<iostream>
#include<cstdio>
#include<tuple>
#include<iomanip>
#include<vector>
#include<bitset>
#include"word.hpp"
#include"gate.hpp"
#include"sequential.hpp"
#include"input_cmp.hpp"
int test_reg(){
  bool clk=0;
  word in;
  word load;
  reg test;
  auto inp=input_cmp((char*)"cmp/Register.cmp",10,1);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    in.set_word(x[1]);
    word ans = test.run(in,(bool)x[2],x[0]);
#ifdef DEBUG
    std::cout<<in.get_word()<<","<<x[2]<<"="<<x[3]<<std::endl;
#endif
    if(ans.get_word()!=x[3])return -1;
    clk=gate::_not(clk);
  }
  return 0;
}
int test_RAM8(){
  bool clk=0;
  word in;
  word load;
  RAM8 test;
  auto inp=input_cmp((char*)"cmp/RAM8.cmp",10,1);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    in.set_word((int16_t)x[1]);
    word ans = test.run(in,(bool)x[2],x[3],x[0]);
    #ifdef DEBUG
    std::cout<<in.get_word()<<","<<x[2]<<","<<x[3]<<"="
	     <<ans.get_word()<<std::endl;
    #endif
    if(ans.get_word()!=(int16_t)x[4])return -1;
    clk=gate::_not(clk);
  }
  return 0;  
}
int test_RAM64(){
  word in;
  word load;
  RAM64 test;
  auto inp=input_cmp((char*)"cmp/RAM64.cmp",10,1);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    in.set_word((int16_t)x[1]);
    word ans = test.run(in,(bool)x[2],x[3],x[0]);
    #ifdef DEBUG
    std::cout<<in.get_word()<<","<<x[2]<<","<<x[3]<<"="
	     <<ans.get_word()<<std::endl;
    #endif
    if(ans.get_word()!=(int16_t)x[4])return -1;
  }
  return 0;  
}
int test_RAM512(){
  word in;
  word load;
  RAM512 test;
  auto inp=input_cmp((char*)"cmp/RAM512.cmp",10,1);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    in.set_word((int16_t)x[1]);
    word ans = test.run(in,(bool)x[2],x[3],x[0]);
    #ifdef DEBUG
    std::cout<<in.get_word()<<","<<x[2]<<","<<x[3]<<"="
	     <<ans.get_word()<<std::endl;
    #endif
    if(ans.get_word()!=(int16_t)x[4])return -1;
  }
  return 0;  
}
int test_RAM4K(){
  word in;
  word load;
  RAM4K test;
  auto inp=input_cmp((char*)"cmp/RAM4K.cmp",10,1);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    in.set_word((int16_t)x[1]);
    word ans = test.run(in,(bool)x[2],x[3],x[0]);
    #ifdef DEBUG
    std::cout<<in.get_word()<<","<<x[2]<<","<<x[3]<<"="
	     <<ans.get_word()<<std::endl;
    #endif
    if(ans.get_word()!=(int16_t)x[4])return -1;
  }
  return 0;  
}
int test_RAM16K(){
  word in;
  word load;
  RAM16K test;
  auto inp=input_cmp((char*)"cmp/RAM16K.cmp",10,1);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    in.set_word((int16_t)x[1]);
    word ans = test.run(in,(bool)x[2],x[3],x[0]);
    #ifdef DEBUG
    std::cout<<in.get_word()<<","<<x[2]<<","<<x[3]<<"="
	     <<ans.get_word()<<std::endl;
    #endif
    if(ans.get_word()!=(int16_t)x[4])return -1;
  }
  return 0;  
}
int test_PC(){
  word in;
  word load;
  PC test;
  auto inp=input_cmp((char*)"cmp/PC.cmp",10,1);
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){
    in.set_word((int16_t)x[1]);
    word ans = test.run(in,(bool)x[2],x[3],x[4],x[0]);
    #ifdef DEBUG
    std::cout<<in.get_word()<<","<<x[2]<<","<<x[3]<<","<<x[4]<<"="
	     <<ans.get_word()<<std::endl;
    #endif
    if(ans.get_word()!=(int16_t)x[5])return -1;
  }
  return 0;  
}

int main(){
  if(test_reg()==-1)return -1;
  if(test_RAM8()==-1)return -1;
  if(test_RAM64()==-1)return -1;
  if(test_RAM512()==-1)return -1;
  if(test_RAM4K()==-1)return -1;
  if(test_RAM16K()==-1)return -1;
  if(test_PC()==-1)return -1;
  
  return 0;
}
