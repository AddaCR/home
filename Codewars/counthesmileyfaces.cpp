//count the smiley faces

#include <string>
#include <iostream>
#include <vector>

int countSmileys(std::vector<std::string> arr)
{
  int size = arr.size();
  int numberOfSmileys = 0;

  for (auto i = arr.begin(); i!= arr.end(); i++) {
    std::string smileyCheck = *i;
    
    int sizeSmiley = smileyCheck.size();

    bool eyes = false; //eyes check
    bool nose = false; //nose check
    bool mouth = false; //mouth check
     
    if (smileyCheck[0] == ':' or smileyCheck[0] == ';') eyes = true;
    if (sizeSmiley == 2)
    {
      nose = true;
      if (smileyCheck[1] == ')' or smileyCheck[1] == 'D') mouth = true;
    }
    else if (sizeSmiley == 3)
    {
      if (smileyCheck[1] == '-' or smileyCheck[1] == '~') nose = true;
      if (smileyCheck[2] == ')' or smileyCheck[2] == 'D') mouth = true;
    }

    if (eyes && nose && mouth) numberOfSmileys++;
  }
  return(numberOfSmileys);
}