//square into squares protect trees

#include <cmath>

class Decomp
{
  public:
  static std::vector<long long> decompose(long long n);
};

std::vector<long long> Decomp::decompose(long long n)
{
  std::cout << n << std::endl;
  std::vector<long long> res = {n};
  long long goal = 0;
  
  while (res.size()!=0)
  {
    long long current = res.back();
    res.pop_back();

    goal += current*current;
    for (long long i=current-1; i>=0; --i)
    {
      if (goal - i*i>=0)
      {
        goal -= i*i;
        res.push_back(i);
        
        if (goal==0)
        {
          sort(res.begin(), res.end());
          return res;
        }
      }
    }
  }
  
  return {};
}