#pragma once
#define WORD_SIZE 16
class word{
private:
  bool word[WORD_SIZE];
public:
  void set(int i,bool n);
  bool get(int i);
  void print();
};


inline void word::set(int i,bool n){
    word[i]=n;
  }
inline bool word::get(int i){
  return word[i];
}

inline void word::print(){
  for(int i=0;i<WORD_SIZE;i++){
    std::cout<<word[i];
  }
  std::cout<<"\n";
}


