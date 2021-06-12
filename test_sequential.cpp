#include<iostream>
#include<cstdio>
#include<tuple>
#include<iomanip>
#include<vector>
#include"word.hpp"
#include"gate.hpp"
#include"sequential.hpp"
#include"input_cmp.hpp"
int test_reg(){
  bool clk=0;
  word in;
  word load;
  reg test;
  auto inp=input_cmp((char*)"cmp/Register.cmp");
  if(inp[0][0]==-1){
    std::cout<< "ファイルが開けませんでした"<<std::endl;
    return -1;
  }
  for(auto x:inp){
    in.set_word(x[1]);
    word ans = test.run(in,(bool)x[2],clk);
    if(ans.get_word()!=x[3])return -1;
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
