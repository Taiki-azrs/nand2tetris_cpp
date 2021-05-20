#include<iostream>
#include<cstdio>
#include<tuple>
#include"word.hpp"
#include"gate.hpp"
#include"sequential.hpp"
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

int main(){
  test_bit();
  return 0;
}
