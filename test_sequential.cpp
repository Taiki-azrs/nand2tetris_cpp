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
  auto inp=input_cmp((char*)"cmp/Register.cmp",3);
  if(inp[0][0]==-1){
    std::cout<< "ファイルが開けませんでした"<<std::endl;
    return -1;
  }
  for(auto x:inp){
    in.set_word(x[0]);
    word ans = test.run(in,(bool)x[1],clk);
    if(ans.get_word()!=x[2])return -1;
    clk=gate::_not(clk);
  }
  return 0;
}


int main(){
  if(test_reg()==-1){
    std::cout<<"error test_reg"<<std::endl;
    return -1;
  }
  return 0;
}
