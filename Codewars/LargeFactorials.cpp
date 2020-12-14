//Large factorials

#include <string>
#include <vector>
using namespace std;

std::string multiply(std::string a, std::string b)
{
   int len1 = a.length();
   int len2 = b.length();

   if (!a.length() || !b.length())
      return "";

   if (len1 == 0 || len2 == 0)
      return "0";

   std::vector<int> result(len1 + len2, 0);

   int ia = 0;
   int ib = 0;

   for (int i = len1 - 1; i >= 0; i--)
   {
      int carry = 0;
      int n1 = a[i] - '0';
      ib = 0;

      for (int j = len2 - 1; j >= 0; j--)
      {
         int n2 = b[j] - '0';
         int sum = n1 * n2 + result[ia + ib] + carry;
         carry = sum / 10;
         result[ia + ib] = sum % 10;
         ib++;
      }

      if (carry > 0)
         result[ia + ib] += carry;

      ia++;
   }

   int i = result.size() - 1;
   while (i >= 0 && result[i] == 0)
      i--;

   if (i == -1)
      return "0";

   std::string s = "";
   while (i >= 0)
      s += std::to_string(result[i--]);

   return s;
}

string factorial(int factorial){
   std::string result = "1";
   for (int i = 1; i <= factorial; i++)
   {
      result = multiply(std::to_string(i), result);
   }
   return result;
}