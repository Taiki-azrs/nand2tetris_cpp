#pragma once
namespace adder{
  std::tuple<bool,bool>half_adder(bool a,bool b);
  std::tuple<bool,bool>full_adder(bool a,bool b,bool c);
  word add16(word a,word b);
  word inc16(word a);
}
