//some egyptian fractions

#include <string>

class Decomp
{
public:
  static std::string decompose(const std::string &nrStr, const std::string &drStr)
   {
     std::string egy{"["};
     int n1 = std::stoi(nrStr),n2 = std::stoi(drStr);
     long s = n1,nm = n2,nd;
     if(!n1) return "[]";
     if((nd = n2/n1) < 1)
      if((s = n1%n2) == 0)
       return "[" + std::to_string(n1/n2) + "]";
      else
       { nd = n2/s + 1;
         egy += std::to_string(n1/n2); 
         if(n2%s == 0) return egy + ", 1/" + std::to_string(n2/s) + "]"; }
     else 
      { egy += "1/"+std::to_string((n2%n1)?++nd:nd);
        if(n2%n1 == 0) return egy + "]"; }
     do {
          s = s*nd - nm;
          nm *= nd;
          nd = (nm % s)?(nm / s + 1):(nm / s);
          egy += ", 1/"+std::to_string(nd); }
     while(s != 1 && nm % s);
     return egy + "]"; }
};