#include<iostream>
#include<cstdio>
#include<tuple>
#include"word.hpp"
namespace gate{
  bool _nand(bool a,bool b){
    return !(a && b);
  }
  bool _not(bool a){
    return _nand(a,a);
  }
  bool _and(bool a,bool b){
    return _not(_nand(a,b));
  }
  bool _or(bool a,bool b){
    return _nand(_nand(a,a),_nand(b,b));
  }
  bool _xor(bool a,bool b){
    bool tmp=_nand(a,b);
    return _nand(_nand(a,tmp),_nand(b,tmp));
  }
  bool _mux(bool a,bool b,bool sel){
    bool nsel=_not(sel);
    return _or(_and(nsel,a),_and(sel,b));
  }
  std::tuple<bool,bool> _dmux(bool in,bool sel){
    bool a=_and(_not(sel),in);
    bool b=_and(sel,in);
    return std::forward_as_tuple(a,b);
  }
  word _and16(word a,word b){
    word out;
    for(int i=0;i<WORD_SIZE;i++){
      out.set(i,_and(a.get(i),b.get(i)));
    }
    return out;
  }
  word _or16(word a,word b){
    word out;
    for(int i=0;i<WORD_SIZE;i++){
      out.set(i,_or(a.get(i),b.get(i)));
    }
    return out;
  }
  word _not16(word a){
    word out;
    for(int i=0;i<WORD_SIZE;i++){
      out.set(i,_not(a.get(i)));
    }
    return out;
  }
  word _mux16(word a,word b,bool sel){
    word out;
    for(int i=0;i<WORD_SIZE;i++){
      out.set(i,_mux(a.get(i),b.get(i),sel));
    }
    return out;
  }
}
