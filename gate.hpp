#pragma once
#include<vector>
namespace gate{
  bool _nand(bool a,bool b);
  bool _not(bool a);
  bool _and(bool a,bool b);
  bool _or(bool a,bool b);
  bool _xor(bool a,bool b);
  bool _mux(bool a,bool b,bool sel);
  std::vector<bool> _dmux(bool in,bool sel);
  word _and16(word a,word b);
  word _or16(word a,word b);
  word _xor16(word a,word b);
  word _not16(word a);
  word _mux16(word a,word b,bool sel);
  word _mux4way16(word a,word b,word c,word d,int16_t sel);
  std::vector<bool> _dmux4way(bool in,int16_t sel);
  std::vector<bool> _dmux8way(bool in,int16_t sel);
  word _mux8way16(word a,word b,word c,word d,word e,word f,word g,word h,int16_t sel);
  bool _or16way(word a);
  
}
