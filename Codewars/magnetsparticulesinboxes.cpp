//magnet particules in boxes 

#include <math.h>

class Magnets
{
public:
  
    static double force_box(int k , int n)
    {
      double base = ((double)n + 1);
      return 1.0 / ((double)k * pow(base, 2*k));
    }
                     
    static double force_row(int k, int n)
    {
      double total = 0.0;
      for(int i = 1; i <= n; i++)
      {
        total += force_box(k, i);
      }
      return total;
    }
  
  
    static double doubles(int maxk, int maxn)
    {
      double total = 0.0;
      for(int i = 1; i <= maxk; i++)
      {
        total += force_row(i, maxn);
      }
      return total;
    }
};