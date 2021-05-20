#include<iostream>
#include<cstdio>
#include<tuple>
#include<iomanip>
#include<vector>
#include"word.hpp"
#include"gate.hpp"
#include"sequential.hpp"
#include"input_cmp.hpp"
void test_bit(){
  bool clk=0;
  word in;
  word load;
  bit test;
  in.set_word(0b1100110011110000);
  load.set_word(0b1111000011001100);
  for(int i=0;i<16;i++){
    bool ans = test.run(in.get(i),load.get(i),clk);
    std::cout<<in.get(i)<<","<<load.get(i)<<","<<ans<<std::endl;
    clk=gate::_not(clk);
  }
}
int test_reg(){
  bool clk=0;
  word in;
  word load;
  reg test;
  auto inp=input_cmp((char*)"Register.cmp",3);
  for(auto x:inp){
    in.set_word(x[0]);
    word ans = test.run(in,(bool)x[1],clk);
    //std::cout<<std::setw(10)<<x[0]<<","<<x[1]<<","<<ans.get_word()<<std::endl;
    if(ans.get_word()!=x[2])return -1;
    clk=gate::_not(clk);
  }
  return 0;
}


int main(){
  if(test_reg()==-1){
    std::cout<<"error"<<std::endl;
  }else{
    std::cout<<"OK"<<std::endl;
  }
  return 0;
}
