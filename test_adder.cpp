#include<iostream>
#include<cstdio>
#include<tuple>
#include<bitset>
#include"input_cmp.hpp"
#include"word.hpp"
#include"gate.hpp"
#include"adder.hpp"
int test_half_adder(){
  auto inp=input_cmp((char*)"cmp/HalfAdder.cmp");
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    auto ans = adder::half_adder(x[0],x[1]);
    #ifdef DEBUG
    std::cout <<"half_adder("<<x[0]<<","<<x[1]<<")= ("<<std::get<0>(ans) <<","
	      <<std::get<1>(ans)<<")"<<std::endl;
    #endif
    if(std::get<0>(ans)!=x[2] || std::get<1>(ans)!=x[3])return -1;
  }
  return 0;
}

int test_full_adder(){
  auto inp=input_cmp((char*)"cmp/FullAdder.cmp");
  if(inp[0][0]==-1){
    return -1;
  }
  for(auto x:inp){    
    auto ans = adder::full_adder(x[0],x[1],x[2]);
    #ifdef DEBUG
    std::cout <<"full_adder("<<x[0]<<","<<x[1]<<","<<x[2]<<")= ("<<std::get<0>(ans) <<","
	      <<std::get<1>(ans)<<")"<<std::endl;
    #endif
    if(std::get<0>(ans)!=x[3] || std::get<1>(ans)!=x[4])return -1;
  }
  return 0;
}  

int test_add16(){
  auto inp=input_cmp((char*)"cmp/Add16.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  word a,b;
  for(auto x:inp){
    a.set_word(x[0]);
    b.set_word(x[1]);
    auto ans = adder::add16(a,b);
    #ifdef DEBUG
    std::cout <<"add16("<<std::bitset<16>(x[0])<<","<<std::bitset<16>(x[2])<<")= ("
	      <<std::bitset<16>(ans.get_word())<<")"<<std::endl;
    #endif
    if(ans.get_word()!=(int16_t)x[2])return -1;
  }
  return 0;  
}
/*
int test_inc16(){
  std::cout << "===inc16===" << std::endl;
  word a;
  for(int i=0;i<WORD_SIZE;i++){
    a.set(i,i%2);
  }
  word c=adder::inc16(a);
  a.print();
  std::cout <<"+"<<std::endl;
  std::cout<<"1"<<std::endl;
  c.print();
}
int test_alu(){
  word x,y;
  x.set_word(0b0000000000000000);
  y.set_word(0b1111111111111111);
  bool zx=0,nx=1,zy=0,ny=1,f=0,no=1;
  auto out=adder::alu(x,y,zx,nx,zy,ny,f,no);
  std::get<0>(out).print();
  std::cout<<std::get<1>(out)<<","<<std::get<2>(out)<<std::endl;
}
*/			       
int main(){
  if(test_half_adder()==-1)return -1;
  if(test_full_adder()==-1)return -1;
  if(test_add16()==-1)return -1;
  // test_full_adder();
  // test_add16();
  // test_inc16();
  //test_alu();
  return 0;
}
