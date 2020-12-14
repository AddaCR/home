//factorial tail
int Zeroes (int base, int number)
{
  int o_num = number, prime, prime_mult, prime_power;
  int zeroes = 0, num_div = 0;
  for(prime=2; prime <= base; ++prime) {
    number = o_num; prime_mult = 0; prime_power = prime; num_div = 0;
    while(base % prime == 0) {
      base /= prime;
      ++prime_mult;
    }
    if(prime_mult > 0) {
      while(number >= prime_power) {
        num_div += number / prime_power;
        prime_power *= prime;
      }
      if(zeroes == 0 || num_div/prime_mult < zeroes) {
        zeroes = num_div/prime_mult;
      }
    }
  }
  return zeroes;
}