//integers recreation one

#include <utility>
#include <vector>
#include <cmath>

class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n) {
      std::vector<std::pair<long long, long long>> ans;
      for (long long i = m; i <= n; ++i) {
        long long num = i;
        long long sum = 0;
        for (long long j = 1; j*j <= i; ++j) {
          if (num % j == 0) {
            sum += j * j;
            if (j != num / j)
              sum += (num / j) * (num / j);
          }
        }
        // is sum a perfect square?
        if (sum == std::round(sqrt(sum)) * std::round(sqrt(sum))) {
          ans.push_back(std::make_pair(num, sum));
        }
      }
      return ans;
    }
};