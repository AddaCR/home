//calculate sinx
double sin(double deg)
{    
    double pii = 3.14159265358979323846;
    double denominator, term, sinx;
    double x = deg * pii / 180.0;
    term = x;
    sinx = term;
    for(int n = 1;n < 8; n++)
    {
        denominator = 2 * n * (2 * n + 1);
        term = -term * x * x / denominator;
        sinx = sinx + term;
    } 
  
  return sinx;
}