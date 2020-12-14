// Fake binary
#include <string>

std::string fakeBin(std::string str){
  for(auto a = 0; a < str.length(); a++)
  {
    if((str[a] - '0') < 5)
    {
      str[a] = '0';
      continue;
    }
    if((str[a] - '0') >= 5)
    {
      str[a] = '1';
    }
  }
  return str;
}