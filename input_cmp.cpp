#include<iostream>
#include<fstream>
#include<vector>
std::vector<std::string> split(std::string str, char del) {
  int first = 0;
  int last = str.find_first_of(del);
 
  std::vector<std::string> result;
 
  while (first < str.size()) {
    std::string subStr(str, first, last - first);
 
    result.push_back(subStr);
 
    first = last + 1;
    last = str.find_first_of(del, first);
 
    if (last == std::string::npos) {
      last = str.size();
    }
  }
 
  return result;
}
std::vector<std::vector<int>> input_cmp(char* filename,int radix=10,bool clk_flag=0)
{
  std::ifstream ifs(filename);
  if(!ifs){
    std::vector<std::vector<int>> err(1,std::vector<int>(1,-1));
    std::cout<< "ファイルが開けませんでした"<<std::endl;
    return err;
  }
  std::vector<std::vector<int>> out;
  std::string data;
  std::getline(ifs,data);
  int i=0;
  while(!ifs.eof()){
    std::getline(ifs,data);
    if(data.empty())break;
    std::vector<std::string>wd=split(data,'|');
    std::vector<int> tmp;
    for(int j=0;j<wd.size();j++){
      
      try{
	if(clk_flag==1 && j==1){
	  if(wd[j].find("+")!=std::string::npos){
	    tmp.push_back(0);
	  }else{
	    tmp.push_back(1);
	  }
	}else{
	  tmp.push_back(std::stoi(wd[j],0,radix));
	}
      }
      catch(const std::invalid_argument& e){
	
      }

    }
    /*
    for(int i=0;i<tmp.size();i++){std::cout<<tmp[i]<<",";} //dump tmp
    std::cout<<std::endl;
    */
    out.push_back(tmp);
  }
  return out;
}
