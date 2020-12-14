//parse int() reloaded

#include <string>
#include <map>

std::map<std::string, long> nameToValue{
  {"zero", 0},
  {"one", 1},
  {"two", 2},
  {"three", 3},
  {"four", 4},
  {"five", 5},
  {"six", 6},
  {"seven", 7},
  {"eight", 8},
  {"nine", 9},
  {"ten", 10},
  {"eleven", 11},
  {"twelve", 12},
  {"thirteen", 13},
  {"fourteen", 14},
  {"fifteen", 15},
  {"sixteen", 16},
  {"seventeen", 17},
  {"eighteen", 18},
  {"nineteen", 19},
  {"twenty", 20},
  {"thirty", 30},
  {"forty", 40},
  {"fifty", 50},
  {"sixty", 60},
  {"seventy", 70},
  {"eighty", 80},
  {"ninety", 90},
  {"hundred", 100},
  {"thousand", 1000},
  {"million", 1000000},
  {"and", -1}
};

const std::string separators = " -";

long parse_int(std::string number) {
  
  if (number.empty()) {
    
    return 0;
  }
  else if (number.length() > 7 && number.compare(number.length() - 7, 7, "million") == 0) {
    
    return 1000000;
  }
  
  int start = 0;
  int end = 0;
  
  long ch = 0;
  long result = 0;
  
  do {
    
    end = number.find_first_of(separators, start);
    
    if (end < 0) {
      
      end = number.size();
    }
    
    long value = nameToValue[number.substr(start, end - start)];
    
    if (value < 0) {
      
    }
    else if (value < 100) {
      
      ch += value;
    }
    else if (100 == value) {
      
      result += ch * 100;
      ch = 0;
      
    }
    else if (1000 == value) {
      
      result = (result + ch) * 1000;
      ch = 0;
    }
    
    start = number.find_first_not_of(separators, end);
  }
  while(start > 0);
  
  result += ch;
  
  return result;
}