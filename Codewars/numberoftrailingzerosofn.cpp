// Trailing zeros
long zeros(long n) {

  //more occurences of 2 than 5.
  long acc = 5;
  long fives = 0;
  while(acc < n) {
    fives += n / acc;
    acc *= 5;
  }
  return fives;
}