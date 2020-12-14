//smallest possible sum

#include <vector>
using namespace std;
int minIndex(vector<unsigned long long> arr)
{
    int index = 0; unsigned long long min = arr[index];
    for(int i = 1; i < arr.size(); i++)
    {
        if(min > arr[i])
        {
            index = i;
            min = arr[index];
        }
    }
    return index;
}
 
bool isValid(vector <unsigned long long> arr)
{
    for(int i = 0; i < arr.size() - 1; i++)
        if(arr[i] != arr[i + 1])
            return false;
    return true;
}
unsigned long long solution(const vector<unsigned long long>& arr)
{
  vector<unsigned long long> copy(arr);
  while(!isValid(copy))
  {
      int min_index = minIndex(copy);
      for(int i = 0; i < arr.size(); i++)
      {
          if(copy[i] % copy[min_index] == 0)
              copy[i] = copy[min_index];
          else
              copy[i] %= copy[min_index];
      }
  }
    unsigned long long sum = 0;
    for(unsigned long long value : copy)
        sum += value;
    return sum;
}