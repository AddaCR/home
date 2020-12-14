// which x for that sum
#include<cmath>
using namespace std;


double solve(double m)
{
  double delta = (4+(1./m))*(1./m);
  double b     = -(2+(1./m));
  double alpha = (-b - sqrt(delta))*0.5;
  return alpha;
}