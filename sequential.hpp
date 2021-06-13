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

class reg{
private:
  bit w[16];
  word out;
public:
  word run(word in,bool load,bool clk);
};
/*
class RAM8{
private:
  reg n[8];
  word out;
public:
  word run(word in,int16_t address,bool load,word out,bool clk);
}
*/
