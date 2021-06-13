#include<iostream>
#include<cstdio>
#include<tuple>
#include<vector>
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
  std::vector<bool> _dmux(bool in,bool sel){
    std::vector<bool> out(2);
    out[0]=_and(_not(sel),in);
    out[1]=_and(sel,in);
    return out;
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
  word _xor16(word a,word b){
    word out;
    for(int i=0;i<WORD_SIZE;i++){
      out.set(i,_xor(a.get(i),b.get(i)));
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
  word _mux4way16(word a,word b,word c,word d,int16_t sel){
    bool L=sel&0b01;
    bool H=sel>>1;
    word tmp1=_mux16(a,b,L);
    word tmp2=_mux16(c,d,L);
    word out=_mux16(tmp1,tmp2,H);
    return out;
  }
  std::vector<bool> _dmux4way(bool in,int16_t sel){
    bool L=sel&0b01;
    bool H=sel>>1;
    auto tmp=_dmux(in,L);
    std::vector<bool> out(4,0);
    out[0]=_and(tmp[0],_not(H));
    out[1]=_and(tmp[1],_not(H));
    out[2]=_and(tmp[0],H);
    out[3]=_and(tmp[1],H);
    return out;
  }
  std::vector<bool> _dmux8way(bool in,int16_t sel){
    int16_t m=sel&0b011;
    bool n=sel>>2;
    auto tmp=_dmux4way(in,m);
    std::vector<bool> out(8);
    out[0]=_and(tmp[0],_not(n));
    out[1]=_and(tmp[1],_not(n));
    out[2]=_and(tmp[2],_not(n));
    out[3]=_and(tmp[3],_not(n));
    out[4]=_and(tmp[0],n);
    out[5]=_and(tmp[1],n);   
    out[6]=_and(tmp[2],n);   
    out[7]=_and(tmp[3],n);
    return out;
  }
  word _mux8way16(word a,word b,word c,word d,word e,word f,word g,word h,int16_t sel){
    int16_t m=sel&0b011;
    bool n=sel>>2;
    word tmp1=_mux4way16(a,b,c,d,m);
    word tmp2=_mux4way16(e,f,g,h,m);
    word out=_mux16(tmp1,tmp2,n);
    return out;
  }
  
  bool _or16way(word a){
    bool out=0;
    for(int i=0;i<WORD_SIZE;i++){
      out=_or(a.get(i),out);
    }
    return out;
  }
}
