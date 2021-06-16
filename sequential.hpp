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
  bool out=0;
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

class RAM8{
private:
  reg ram[8];
  word out;
public:
  word run(word in,bool load,int16_t address,bool clk);
};
class RAM64{
private:
  RAM8 ram[8];
  word out;
public:
  word run(word in,bool load,int16_t address,bool clk);
};
class RAM512{
private:
  RAM64 ram[8];
  word out;
public:
  word run(word in,bool load,int16_t address,bool clk);
};
class RAM4K{
private:
  RAM512 ram[8];
  word out;
public:
  word run(word in,bool load,int16_t address,bool clk);
};
class RAM16K{
private:
  RAM4K ram[8];
  word out;
public:
  word run(word in,bool load,int16_t address,bool clk);
};
