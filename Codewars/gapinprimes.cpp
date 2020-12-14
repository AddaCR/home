// gap in primes

class GapInPrimes
{
public:
 static  std::pair <long long, long long> gap(int g, long long m, long long n);
  
  private:
  static bool isPrime(int n);
};

bool GapInPrimes::isPrime(int n)
{
    if (n <= 1)  return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) return false;
    }
 
    return true;
 }

  
std::pair <long long, long long> GapInPrimes::gap(int g, long long m, long long n)
{
  std::pair <long long, long long> pair = {0, 0};
  for(int i = m; i <= n-g; i++)
  {
    bool isSuccessivePrime = true;
    if (g % 2) continue;
    if (!isPrime(i) || !isPrime(i+g)) continue;
    for (int j = i+2; j < i+g; j+=2)
    {
      if (isPrime(j))
      {
        isSuccessivePrime = false;
        break;
      }
    }
    if (!isSuccessivePrime) continue;
    pair = {i, i+g};
    return pair;
  }
  return pair;
}