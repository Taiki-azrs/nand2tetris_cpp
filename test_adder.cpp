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

int test_inc16(){
  auto inp=input_cmp((char*)"cmp/Inc16.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  word in;
  for(auto x:inp){
    in.set_word(x[0]);
    auto ans = adder::inc16(in);
    #ifdef DEBUG
    std::cout <<"inc16("<<std::bitset<16>(x[0])<<")= ("
	      <<std::bitset<16>(ans.get_word())<<")"<<std::endl;
    #endif
    if(ans.get_word()!=(int16_t)x[1])return -1;
  }
  return 0;  
}
int test_alu(){
  word x,y;
  bool zx,nx,zy,ny,f,no;
  auto inp=input_cmp((char*)"cmp/ALU.cmp",2);
  if(inp[0][0]==-1){
    return -1;
  }
  word in;
  for(auto i:inp){
    x.set_word(i[0]);
    y.set_word(i[1]);
    zx=i[2];nx=i[3];zy=i[4];ny=i[5];f=i[6];no=i[7];
    auto ans=adder::alu(x,y,zx,nx,zy,ny,f,no);
    auto out=std::get<0>(ans);
    bool zr=std::get<1>(ans);
    bool ng=std::get<2>(ans);
    #ifdef DEBUG
    std::cout<<std::bitset<16>(x.get_word())<<","<<std::bitset<16>(y.get_word())<<",";
    std::cout<<zx<<","<<nx<<","<<zy<<","<<ny<<","<<f<<","<<no<<",";
    std::cout<<std::bitset<16>(out.get_word())<<","<<zr<<","<<ng<<std::endl;
    #endif
    if(out.get_word()!=(int16_t)i[8] || zr!=i[9] || ng!=i[10])return -1;
  }
  return 0;
}			       
int main(){
  if(test_half_adder()==-1)return -1;
  if(test_full_adder()==-1)return -1;
  if(test_add16()==-1)return -1;
  if(test_inc16()==-1)return -1;
  if(test_alu()==-1)return -1;
  return 0;
}
