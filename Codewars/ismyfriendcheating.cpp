// is my friend cheating

#include <vector>

using namespace std;

class RemovedNumbers
{
public:
  static vector<vector<long long>> removNb(long long n){
      long long sum = (n * n + n)/2;
      vector<vector<long long>> temp;
      for (long long i = 1; i < n; i++){
          double j = (sum - i)/(i + 1.0);
              if ((j < n) && (j == ((long long) j)))
                  temp.push_back({i, j});
      }
      return temp;
  }
};