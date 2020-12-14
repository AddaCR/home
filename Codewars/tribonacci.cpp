//tribonacci sequence

std::vector<int> tribonacci(std::vector<int> s, int n)
{
	std::vector<int> r;
	int t;
	while(n)
	{
		r.push_back(s[0]);
		t = s[0] + s[1] + s[2];
		s[0] = s[1];
		s[1] = s[2];
		s[2] = t;
		n--;
  }
  return r;
}