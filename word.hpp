#pragma once
#define WORD_SIZE 16
class word{
private:
  bool word[WORD_SIZE] = {};
public:
  void set(int i,bool n);
  bool get(int i);
  void print();
  void broadcast(bool n);
  void set_word(int16_t n);
  int16_t get_word();
};


inline void word::set(int i,bool n){
    word[i]=n;
  }
inline bool word::get(int i){
  return word[i];
}
inline void word::broadcast(bool n){
  for(int i=0;i<WORD_SIZE;i++){
    word[i]=n;
  }
}

//以下テストを簡単にするための関数
inline void word::print(){
  for(int i=WORD_SIZE-1;i>=0;i--){
    std::cout<<word[i];
  }
  std::cout<<"\n";
}


inline void word::set_word(int16_t n){
  for(int i=0;i<WORD_SIZE;i++){
    word[i]=((n>>i)&0b1);
  }
}
inline int16_t word::get_word(){
  int16_t out=0;
  for(int i=0;i<WORD_SIZE;i++){
    out=(word[i]<<i)|out;
  }
  return out;
}

