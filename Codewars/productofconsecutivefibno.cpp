//product of consecutive fib numbers

#include <vector>
#include <cmath>
typedef unsigned long long ull;
class ProdFib
{
public:
  static ull fib(ull n)
  {
      if (n == 0 || n == 1) return n;
      ull prev = 0;
      ull curr = 1;
      ull fib_n = 0;
      for (std::size_t i = 2; i <= n; ++i)
      {
          fib_n = (curr + prev);
          prev = curr;
          curr = fib_n;
      }
      return fib_n;
  }
  static std::vector<ull> productFib(ull prod)
  {
      if (prod == 0) return std::vector<ull>{0, 1, 1};
      else if (prod == 1) return std::vector<ull>{1, 1, 1};
      ull prev = 0;
      ull curr = 1;
      ull fib_n = 0;
      ull fib_p = 1;
      ull fib_p_prev = 0;
      for (std::size_t i = 2; i <= std::sqrt(prod); ++i)
      {
          fib_n = (curr + prev);
          fib_p = (curr * prev);
          if (fib_p == prod)
          {
              return std::vector<ull>{prev, curr, 1};
          }
          else if (fib_p_prev < prod && prod < fib_p)
          {
              return std::vector<ull>{prev, curr, 0};
          }
          prev = curr;
          curr = fib_n;
          fib_p_prev = fib_p;
          
      }
      return std::vector<ull>{};
  }
};