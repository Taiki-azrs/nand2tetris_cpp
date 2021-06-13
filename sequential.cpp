#include<iostream>
#include<cstdio>
#include<tuple>
#include"word.hpp"
#include"gate.hpp"
#include"sequential.hpp"
bool dff::run(bool D,bool clk){
  bool tmp1=gate::_nand(D,clk);
  bool tmp2=gate::_nand(tmp1,clk);
  bool ans1=gate::_nand(tmp1,preNQ);
  bool ans2=gate::_nand(preQ,tmp2);
  preQ=ans1;
  preNQ=ans2;
  ans1=gate::_nand(tmp1,preNQ);
  ans2=gate::_nand(preQ,tmp2);
  preQ=ans1;
  preNQ=ans2;
  return preQ;
}

bool bit::run(bool in,bool load,bool clk){
  bool ldst=dload.run(load,clk);
  bool idst=din.run(in,clk);
  bool odst=dout.run(out,clk);
  out=gate::_mux(odst,idst,ldst);
  return out;  
}

word reg::run(word in,bool load,bool clk){
  for(int i=0;i<WORD_SIZE;i++){
    out.set(i,w[i].run(in.get(i),load,clk));
  }
  return out;
}
/*
word RAM8::run(word in,int16_t address,bool load,word out,bool clk){
  
}
*/
