//sum of perfect squares

#include <string>
#include <cmath>

using namespace std;

int sum_of_squares(int n) {
  if (n <= 3)
    return n;
  if (sqrt(n) - floor(sqrt(n)) == 0)
    return 1;
  for (auto i = 1; i <= sqrt(n); i++) {
    if (sqrt(n - i * i) - floor(sqrt(n - i * i)) == 0)
      return 2;
  }
  while (n % 4 == 0)
    n = n / 4;
  return (n % 8 == 7) ? 4 : 3;
}