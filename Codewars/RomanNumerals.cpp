//Roman Numerals Decoder

#include <iostream>
#include <string>

using namespace std;

int solution(string roman) {
   reverse(roman.begin(), roman.end());
   int res = 0;

   for (int i = 0; i < roman.length(); i++)
   {
      if (roman[i] == 'V' && roman[i + 1] == 'I')
      {
         res += 4;
         i++;
         continue;
      }
      if (roman[i] == 'X' && roman[i + 1] == 'I')
      {
         res += 9;
         i++;
         continue;
      }
      if (roman[i] == 'I')
      {
         res++;
         continue;
      }
      if (roman[i] == 'L' && roman[i + 1] == 'X')
      {
         res += 40;
         i++;
         continue;
      }
      if (roman[i] == 'C' && roman[i + 1] == 'X')
      {
         res += 90;
         i++;
         continue;
      }
      if (roman[i] == 'X')
      {
         res += 10;
         continue;
      }
      if (roman[i] == 'D' && roman[i + 1] == 'C')
      {
         res += 400;
         i++;
         continue;
      }
      if (roman[i] == 'M' && roman[i + 1] == 'C')
      {
         res += 900;
         i++;
         continue;
      }
      if (roman[i] == 'C')
      {
         res += 100;
         continue;
      }
      if (roman[i] == 'V')
      {
         res += 5;
         continue;
      }
      if (roman[i] == 'L')
      {
         res += 50;
         continue;
      }
      if (roman[i] == 'D')
      {
         res += 500;
         continue;
      }
      if (roman[i] == 'M')
      {
         res += 1000;
         continue;
      }
   }

   return res;
}