//which are in

class WhichAreIn
{

  public:
  static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2);
};

#include <set>

std::vector<std::string> WhichAreIn::inArray (std::vector<std::string> &array1, std::vector<std::string> &array2)
{
  std::set<std::string> rSet;
  
  for ( auto sub : array1 )
  {
    for ( auto word : array2 )
    {
      if ( word.find( sub ) != std::string::npos )
      {
        rSet.insert( sub );
        break;
      }
    }
  }
  
  std::vector<std::string> r ( rSet.begin(), rSet.end() );
  
  return r;
}