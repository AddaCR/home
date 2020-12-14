// the observed pin

#include <string>
#include <vector>

bool incrementIndexes(std::vector<unsigned int> &indexes, std::vector<std::vector<std::string>> &all_com)
{
  for (unsigned int i = all_com.size() - 1; i >= 0; i--)
  {
    indexes[i]++;
    if (indexes[i] < all_com[i].size())
      break;  
    indexes[i] = 0;
    if (i == 0)
      return true;
  }
  return false;
}

std::vector<std::string> get_pins(std::string observed)
{
  std::vector<std::vector<std::string>> all_com;
  std::vector<unsigned int> indexes;
  std::vector<std::string> ret;
  
  for (unsigned int i = 0; i < observed.size(); i++)
  {
    if (observed[i] == '1')
        all_com.push_back({"1", "2", "4"});
    else if (observed[i] == '2')
        all_com.push_back({"1", "2", "3", "5"});
    else if (observed[i] == '3')
        all_com.push_back({"2", "3", "6"});
    else if (observed[i] == '4')
        all_com.push_back({"1", "4", "5", "7"});
    else if (observed[i] == '5')
        all_com.push_back({"2", "4", "5", "6", "8"});
    else if (observed[i] == '6')
        all_com.push_back({"3", "5", "6", "9"});
    else if (observed[i] == '7')
        all_com.push_back({"4", "7", "8"});
    else if (observed[i] == '8')
        all_com.push_back({"0", "5", "7", "8", "9"});
    else if (observed[i] == '9')
        all_com.push_back({"6", "8", "9"});
    else if (observed[i] == '0')
        all_com.push_back({"0", "8"});
    indexes.push_back(0);
  }

  do
  {
    std::string tmp = "";
    for (unsigned int i = 0; i < all_com.size(); i++)
      tmp += all_com[i][indexes[i]]; 
    ret.push_back(tmp);
  }
  while (!incrementIndexes(indexes, all_com));
    
  return ret;
}