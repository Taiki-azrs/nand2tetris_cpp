#pragma once
class dff{
private:
  bool preQ=0;
  bool preNQ=1;
public:
  bool run(bool D,bool clk);
};

class bit{
private:
  dff dload,din,dout;
  bool out;
public:
  bool run(bool in,bool load,bool clk);
};

