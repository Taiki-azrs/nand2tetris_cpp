#include<iostream>
#include<cstdio>
#include<tuple>
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
}
