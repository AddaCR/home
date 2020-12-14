//tic tac toe like table generator

#include<string>
#include<vector>
using namespace std;
std::string displayBoard(const std::vector<char>& board, unsigned short width){
  int n = board.size();
  int l = n/width;
  int i = 0;
  string res = "";
  while(i < l) {
    for(int j = (i*width);j<(i+1)*width;j++) {
      res += " ";
      res += board[j];
      if(j!=((i+1)*width)-1) {
        res += " ";
        res += "|";
      }
        
      else
        if(j != n-1) {
			res += " ";
			res += "\n"; 
      }   
    }
    if(i!=l-1)
    for(int x=0;x<4*width;x++) {
      if(x!=4*width-1)
        res+= "-";
      else
        res+="\n";     
    }
    i++;
  }
  res += " ";
  cout<<res<<" ";
  return res;
}