//Anagram detection
#include <string>
#include <algorithm>

bool isAnagram(std::string test, std::string original){
  bool a = false;
  std::transform(test.begin(), test.end(), test.begin(), ::tolower);
  std::transform(original.begin(), original.end(), original.begin(), ::tolower);

  if(test.length() != original.length())
    return false;
  for(auto i = 0; i < test.length(); i++)
  {
    for(auto j = 0; j < original.length(); j++)
    {
      if(test[i] == original[j])
      {
        a = true;
        break;
      }
      else
      {
        a = false;
      }
    }
    if (a == false)
      return false;
  }
  return true;
}