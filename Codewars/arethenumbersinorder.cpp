// Are the numbers in order
bool isAscOrder(std::vector<int> arr)
{
    if(arr.size() == 1)
      return true;
    for(auto i = 1; i < arr.size(); i++)
    {
      if(arr[i] < arr[i - 1])
        return false;
    }
    return true;
}