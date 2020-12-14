//Integer Square Root

#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
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


std::string sum_strings(std::string a, std::string b)
{
   std::string sum;
   int aux = 0, mini = 0;

   if (!a.length() || !b.length())
      return "";
   std::reverse(a.begin(), a.end());
   std::reverse(b.begin(), b.end());

   for (int i = 0; i < std::max(a.length(), b.length()); i++)
   {
      if (i >= a.length() && i < b.length())
      {
         aux = (b[i] - '0') + mini;
         mini = aux / 10;
         sum += ((aux % 10) + '0');
      }
      if (i >= b.length() && i < a.length())
      {
         aux = (a[i] - '0') + mini;
         mini = aux / 10;
         sum += ((aux % 10) + '0');
      }
      if (i < b.length() && i < a.length())
      {
         aux = (b[i] - '0') + (a[i] - '0') + mini;
         mini = aux / 10;
         sum += ((aux % 10) + '0');
      }

   }
   if (mini)
      sum += mini + '0';
   std::reverse(sum.begin(), sum.end());
   while (sum[0] == '0')
   {
      sum.erase(0, 1);
   }
   if (sum.length() == 0)
      return "0";
   return sum;
}

std::string division(std::string a, int divisor)
{
  
   std::string result = "";
   if (!a.length())
      return "";
   int i = 0;
   int tmp = a[i] - '0';
   while (tmp < divisor)
      tmp = tmp * 10 + (a[++i] - '0');
 
   while (a.size() > i)
   { 
      result += (tmp / divisor) + '0';
      tmp = (tmp % divisor) * 10 + a[++i] - '0';
   }

   if (result.length() == 0)
      return "0";

   return result;
}

bool isSmaller(std::string str1, std::string str2)
{
   int n1 = str1.length(), n2 = str2.length();
   if (!str1.length() || !str2.length())
      return false;
   if (n1 > n2)
      return false;
   if (n2 > n1)
      return true;
   for (int i = 0; i<n1; i++)
   {
      if (str1[i] < str2[i])
         return true;
      else if (str1[i] > str2[i])
         return false;
   }
   return false;
}

std::string difference(std::string a, std::string b)
{
    if (isSmaller(a, b))
      return "";
   if (!a.length() || !b.length())
      return "";

   std::string str = "";

   int n1 = a.length(), n2 = b.length();

   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());

   int carry = 0;

   for (int i = 0; i<n2; i++)
   {
      int sub = ((a[i] - '0') - (b[i] - '0') - carry);

      if (sub < 0)
      {
         sub = sub + 10;
         carry = 1;
      }
      else
         carry = 0;

      str.push_back(sub + '0');
   }

   for (int i = n2; i<n1; i++)
   {
      int sub = ((a[i] - '0') - carry);
      if (sub < 0)
      {
         sub = sub + 10;
         carry = 1;
      }
      else
         carry = 0;
      str.push_back(sub + '0');
   }

   reverse(str.begin(), str.end());

   return str;
}

std::string search(std::string &left, std::string &right, std::string &input)
{

   if (isSmaller(right, left))
      return "";
   if (right.compare(sum_strings(left, "1")) == 0)
   {
      if (isSmaller(multiply(left, left), input) && isSmaller(input, multiply(right, right)))
         return left;
      return "";
   }


   std::string mid = sum_strings(division(difference(right, left), 2), left);
   std::string mult = multiply(mid, mid);
   std::string simaimult = multiply(sum_strings(mid, "1"), sum_strings(mid, "1"));
   if (isSmaller(mult, input) && isSmaller(input, simaimult))
      return mid;

   std::string aux = multiply(right, right);
   if (isSmaller(aux, input))
   {
      std::string simaimult2 = multiply(sum_strings(right, "1"), sum_strings(right, "1"));
      if (isSmaller(input, simaimult2))
         return right;
      return "";
   }
   std::string aux2 = multiply(sum_strings(left, "1"), sum_strings(left, "1"));
   if (isSmaller(input, aux2))
   {
      std::string simaimult2 = multiply(difference(left, "1"), difference(left, "1"));
      if (isSmaller(simaimult2, input))
         return left;
      return "";
   }

   std::string hei = search(left, mid, input);

   if (hei.empty())
      hei = search(mid, right, input);
   return hei;

}


string integer_square_root(string n) {
 std::string res = division(n, 2);

if (n.length() < 5)
  {
      int h = std::stoi(n);
      int j = (int)sqrt(h);
     return std::to_string(j);
   }


   while (1)
   {
      std::string result = multiply(res, res);

      if (isSmaller(result, n))
      {
         std::string left = division(res, 2);
         res = multiply(res, "2");

         return search(left, res, n);


      }
      res = division(res, 2);

   }
   return "";
}