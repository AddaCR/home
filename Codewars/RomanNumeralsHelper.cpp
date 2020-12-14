//Roman Numerals Helper

#include <string>
#include <unordered_map>
#include <vector>

using std::string; 

struct RomanNum
{  

  string to_roman(int num)
  {         
    string digits;
    string decimals;
    string cents;    
    
    int i = ( num % 10 ) % 5;
    int v = ( num % 10 ) / 5;        
    int x = ((num/10) % 10 ) % 5;          
    int l = ((num/10) % 10 ) / 5;    
    int c = ((num/100) % 10 ) % 5;
    int d = ((num/100) % 10 ) / 5;  
    int m = num / 1000;
      
    if(i == 4 && v) 
    {
      digits = "IX";      
    }
    else if(i == 4 && !v) 
    {
      digits = "IV";
    }
    else 
    {
      digits = string(v, 'V') + string(i, 'I');
    }
    
    if(x == 4 && l) 
    {
      decimals = "XC";      
    }
    else if(x == 4 && !l) 
    {
      decimals = "XL";
    }
    else 
    {
      decimals = string(l, 'L') + string(x, 'X');
    }
    
    if(c == 4 && l) 
    {
      cents = "CM";      
    }
    else if(x == 4 && !l) 
    {
      cents = "CD";
    }
    else 
    {
      cents = string(d, 'D') + string(c, 'C');
    } 
    
    return string(m, 'M') + cents + decimals + digits;  
  }
  
  int from_roman(string str)
  {
    std::unordered_map<string, int> romanTable {
    {"I", 1},
    {"IV", 4},
    {"V", 5},
    {"IX", 9},
    {"X", 10},
    {"XL", 40},
    {"L", 50},
    {"XC", 90},
    {"C", 100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"M", 1000}    
    };
    
    int result = 0;
    std::vector<string> fnNumbers = {"IV", "IX", "XL", "XC", "CD", "CM"};
    
    for(string num : fnNumbers)
    {
      size_t pos = str.find(num);
      if(pos != str.npos)
      {
          result = result + romanTable[num];
          str.erase(pos, 2);
      }
    }

    for(char elem : str)
    {
        result = result + romanTable[string(1, elem)];
    }
    
    return result;   
  }
  
}RomanNumerals;
