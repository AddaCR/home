//take a ten minute walk
#include<vector>

using namespace std;
bool isValidWalk(vector<char> walk) 
{
  
  int vertical=0;
  int horizontal=0;
  int arraySize= walk.size();
  
  if(arraySize!=10)
  {
    return false;
  }
  else
  {
    for(int i=0; i<arraySize; i++)
    {
      if(walk[i]=='n')
        {
          vertical+=1;
        }
      else if(walk[i]=='s')
        {
          vertical-=1;
        }
      
      if(walk[i]=='w')
        {
          horizontal+=1;
        }
      else if(walk[i]=='e')
        {
          horizontal-=1;
        }
    }
    
    if(vertical==0 && horizontal==0)
    {
        return true;
    }
    else 
    {
        return false;
    }
  } 
}