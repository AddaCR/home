//longest common subsequence
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

std::string lcs(const std::string& x, const std::string& y)
{
  std::vector<std::vector<int> > arr;
  arr.resize(x.size() + 1);

  for (int i = 0; i <= x.length(); i++)
    arr[i].resize(y.size() + 1);

  for (int i = x.length() - 1; i >= 0; i--) {
    for (int j = y.length() - 1; j >= 0; j--) {
      if (x[i] == y[j])
        arr[i][j] = 1 + arr[i + 1][j + 1];
      else
        arr[i][j] = std::max(arr[i + 1][j], arr[i][j + 1]);
    }
  }

  std::string res;
  for (int i = 0, j = 0; arr[i][j] != 0 && i < x.length() && j < y.length(); ) {
    if (x[i] == y[j]) {
      res.push_back(x[i]);
      i++;
      j++;
    }
    else {
      if (arr[i][j] == arr[i + 1][j])
        i++;
      else
        j++;
    }
  }

  return res;
}