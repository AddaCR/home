// step in k-primes
#include <math.h>                                                        // <3
namespace KStep{
    bool primeFactors(long long n, int k) { 
      int count = 0;
      while (n % 2 == 0) {
        count++;
        n = n / 2;
        if (count > k)
          return false;
      }
      for (int i = 3; i <= sqrt(n); i = i + 2)
        while (n % i == 0) {
          count++;
          n = n / i;
          if (count > k)
            return false;
        }
      if (n > 2)
        count++;
      return count == k;
    }
  
    std::vector<long long> countKprimes(int k, long long start, long long end){
     std::vector<long long> res;
      for (long long i = start; i <= end; ++i) {
        if (primeFactors(i, k)) {
          res.push_back(i);
        }
      } 
      return res;
    }
    std::vector<std::pair <long, long>> kprimesStep(int k, int step, long long m, long long n){
      std::vector<std::pair <long, long>> res;
      std::vector<long long> v = countKprimes(k, m, n);
      for (int i = 0; i < v.size() - 1; ++i)
        for (int j = i + 1; j < v.size(); ++j)
          if (v[j] - v[i] == step) 
            res.push_back({v[i], v[j]});
      return res;  
    }
}