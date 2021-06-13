#include<iostream>
#include<cstdio>
#include<tuple>
#include"word.hpp"
#include"gate.hpp"
namespace adder{
  std::tuple<bool,bool>half_adder(bool a,bool b){
    bool sum=gate::_xor(a,b);
    bool carry=gate::_and(a,b);
    return std::forward_as_tuple(sum,carry);
  }
  std::tuple<bool,bool>full_adder(bool a,bool b,bool c){
    auto tmp=half_adder(b,c);
    auto tmp2=half_adder(a,std::get<0>(tmp));
    bool sum = std::get<0>(tmp2);
    bool carry = gate::_or(std::get<1>(tmp),std::get<1>(tmp2));
    return std::forward_as_tuple(sum,carry);
  }
  word add16(word a,word b){
    word c;
    auto tmp=half_adder(a.get(0),b.get(0)); //0ビット目は半加算
    c.set(0,std::get<0>(tmp));
    bool carry=std::get<1>(tmp);
    for(int i=1;i<WORD_SIZE;i++){
      tmp=full_adder(carry,a.get(i),b.get(i));
      c.set(i,std::get<0>(tmp));
      carry=std::get<1>(tmp);
    }
    return c;
  }
  word inc16(word in){
    word inc;
    inc.set(0,1);
    return add16(in,inc);    
  }
  std::tuple<word,bool,bool>alu(word x,word y,bool zx,bool nx,bool zy,bool ny,bool f,bool no){
    word wzx;                        //zx
    wzx.broadcast(gate::_not(zx));
    auto calc_x=gate::_and16(x,wzx);
    
    word wnx;                        //nx
    wnx.broadcast(nx);               
    calc_x=gate::_xor16(calc_x,wnx);

    word wzy;                        //zy
    wzy.broadcast(gate::_not(zy));
    auto calc_y=gate::_and16(y,wzy);

    word wny;                        //ny
    wny.broadcast(ny);               
    calc_y=gate::_xor16(calc_y,wny);

    word add_dst=add16(calc_x,calc_y); //f
    word and_dst=gate::_and16(calc_x,calc_y);
    word f16=gate::_mux16(and_dst,add_dst,f);


    word wno;
    wno.broadcast(no);
    f16=gate::_xor16(f16,wno); //no

    bool zr=gate::_not(gate::_or16way(f16));
    bool ng=gate::_or(f16.get(15),0);

    return std::forward_as_tuple(f16,zr,ng);    
  }

}

