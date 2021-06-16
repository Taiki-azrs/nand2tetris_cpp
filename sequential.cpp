#include<iostream>
#include<cstdio>
#include<tuple>
#include"word.hpp"
#include"gate.hpp"
#include"adder.hpp"
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
word RAM8::run(word in,bool load,int16_t address,bool clk){
  auto sel_mem=gate::_dmux8way(load,address);
  word tmp[8];
  for(int i=0;i<8;i++){
    tmp[i]=ram[i].run(in,sel_mem[i],clk);
    }
  out = gate::_mux8way16(tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7],address);
  return out;
}
word RAM64::run(word in,bool load,int16_t address,bool clk){
  int16_t addr_blk=address>>3;
  int16_t addr_mem=address&0b0111;
  auto sel_mem=gate::_dmux8way(load,addr_blk);
  word tmp[8];
  for(int i=0;i<8;i++){
    tmp[i]=ram[i].run(in,sel_mem[i],addr_mem,clk);
    }
  out = gate::_mux8way16(tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7],addr_blk);
  return out;
}
word RAM512::run(word in,bool load,int16_t address,bool clk){
  int16_t addr_blk=address>>6;
  int16_t addr_mem=address&0b0111111;
  auto sel_mem=gate::_dmux8way(load,addr_blk);
  word tmp[8];
  for(int i=0;i<8;i++){
    tmp[i]=ram[i].run(in,sel_mem[i],addr_mem,clk);
    }
  out = gate::_mux8way16(tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7],addr_blk);
  return out;
}
word RAM4K::run(word in,bool load,int16_t address,bool clk){
  int16_t addr_blk=address>>9;
  int16_t addr_mem=address&0b0111111111;
  auto sel_mem=gate::_dmux8way(load,addr_blk);
  word tmp[8];
  for(int i=0;i<8;i++){
    tmp[i]=ram[i].run(in,sel_mem[i],addr_mem,clk);
    }
  out = gate::_mux8way16(tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7],addr_blk);
  return out;
}
word RAM16K::run(word in,bool load,int16_t address,bool clk){
  int16_t addr_blk=address>>12;
  int16_t addr_mem=address&0b0111111111111;
  auto sel_mem=gate::_dmux8way(load,addr_blk);
  word tmp[8];
  for(int i=0;i<8;i++){
    tmp[i]=ram[i].run(in,sel_mem[i],addr_mem,clk);
    }
  out = gate::_mux8way16(tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7],addr_blk);
  return out;
}

word PC::run(word in,bool reset,bool load,bool inc,bool clk){
  word fake,zeros;
  zeros.set_word(0);
  word preout=out.run(fake,0,clk);
  auto inc_data=adder::inc16(preout);
  auto incf=gate::_mux16(preout,inc_data,inc);
  auto loadf=gate::_mux16(incf,in,load);
  auto resetf=gate::_mux16(loadf,zeros,reset);
  return out.run(resetf,1,clk);
}
