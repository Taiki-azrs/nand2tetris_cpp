#pragma once
namespace gate{
  bool _nand(bool a,bool b);
  bool _not(bool a);
  bool _and(bool a,bool b);
  bool _or(bool a,bool b);
  bool _xor(bool a,bool b);
  bool _mux(bool a,bool b,bool sel);
  std::tuple<bool,bool> _dmux(bool in,bool sel);
}
