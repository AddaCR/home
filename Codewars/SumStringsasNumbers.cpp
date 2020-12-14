// Sum Strings as Numbers

#include <string>
#include <algorithm>

std::string sum_strings(std::string a, std::string b)
{
  std::string sum;
  int aux = 0, mini = 0;
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