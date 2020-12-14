//goind to 0 or infinity

#include <cmath>

class Suite
{
public:

    static double truncate(double value, unsigned int digits)
    {
        double f = pow(10, digits);
        return ((int) (value * f)) / f;
    }
  
    static long double factorial(int value, int stop = 1)
    {
      long double result = 1;
      for (int i = value; i > stop; i--)
      {
        result *= i;
      }
      return result;
    }
        
    static double going(int n) {
      double sum = 0;
      
      for (int i = 1; i <= n; i++)
      {
        sum += 1 / factorial(n, i);
      }
      
      return truncate(sum, 6);    
    }
};