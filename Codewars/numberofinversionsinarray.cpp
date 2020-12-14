//calculate number of inversion in array
#include <vector>

class Kata {
public:
  int countInversions(const std::vector<int>& vec) {
    int count = 0;
    for (size_t i = 0; i < vec.size(); ++i)
    {
      for (size_t j = i + 1; j < vec.size(); ++j)
      {
        if (vec[j] < vec[i])
        {
          ++count;
        }
      }
    }
    return count;
  }
};