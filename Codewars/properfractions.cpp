//number of proper fractions

long properFractions(long n) {
  if(n == 1)
    return 0;
  long result = n;
  long m = n, c = 2;
  while(m > 1 && c * c <= m) {
    if(m % c == 0) {
      result = (result / c) * (c - 1);
      while(m % c == 0) {
        m = m / c;
      }}
    if(c == 2)
      c = 3;
    else if(c == 3)
      c = 5;
    else if (c % 6 == 5)
      c += 2;
    else
      c += 4;
  }
  if(m != 1) {
    result = (result / m) * (m - 1);
  }
  return result;
}