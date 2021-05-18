#include<iostream>
#include<cstdio>
#include<tuple>
#include"word.hpp"
#include"gate.hpp"
namespace adder{
  std::tuple<bool,bool>half_adder(bool a,bool b){
    bool sum=gate::_xor(a,b);
    bool carry=gate::_and(a,b);
    return std::forward_as_tuple(carry,sum);
  }
  std::tuple<bool,bool>full_adder(bool a,bool b,bool c){
    auto tmp=half_adder(b,c);
    auto tmp2=half_adder(a,std::get<1>(tmp));
    bool sum = std::get<1>(tmp2);
    bool carry = gate::_or(std::get<0>(tmp),std::get<0>(tmp2));
    return std::forward_as_tuple(carry,sum);
  }
  word add16(word a,word b){
    word c;
    auto tmp=half_adder(a.get(0),b.get(0)); //0ビット目は半加算
    c.set(0,std::get<1>(tmp));
    bool carry=std::get<0>(tmp);
    for(int i=1;i<16;i++){
      tmp=full_adder(carry,a.get(i),b.get(i));
      c.set(i,std::get<1>(tmp));
      carry=std::get<0>(tmp);
    }
    return c;
  }
  word inc16(word in){
    word inc;
    inc.set(0,1);
    return add16(in,inc);
    
  }

}

