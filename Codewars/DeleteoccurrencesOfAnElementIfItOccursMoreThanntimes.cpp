// Delete occurrences of an element if it occurs more than n times

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::vector<int> aux = arr;
    for(auto i = aux.begin(); i < aux.end(); i++)
    {
      int count = 0;
      for(auto j = aux.begin(); j < aux.end(); j++)
      {
        if(*i == *j)
        {
          count++;
          if(count > n)
          {
            j = aux.erase(j);
            j--;
          }
        }
      }
    }
    return aux;
    
}