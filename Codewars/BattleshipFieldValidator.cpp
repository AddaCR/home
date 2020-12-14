// Battleship field validator

#include <iostream>
#include <vector>

using namespace std;

bool validate_battlefield(vector< vector<int> > field) {
  // Write your magic here ;)
  int sub = 4, des = 3, cruz = 2, bat = 1;
  for (auto i = 0; i < 10; i++)
  {
    for (auto j = 0; j < 10; j++)
    {
      if (field[i][j])
      {
        if(i > 1 && j > 1)
          if( field[i+1][j-1] )
            return false;
        if (field[i][j + 1])
        {
          if (field[i][j + 2])
          {
            if (field[i][j + 3])
            {
              bat--;
              field[i][j + 3] = 0;
              field[i][j + 2] = 0;
              field[i][j + 1] = 0;
              field[i][j] = 0;
              if (field[i+1][j+4] || field[i][j + 4] || field[i + 1][j + 3] || field[i + 1][j + 2] || field[i + 1][j + 1] || field[i + 1][j])
                return false;
              continue;
            }
            cruz--;
            field[i][j + 2] = 0;
            field[i][j + 1] = 0;
            field[i][j] = 0;
            if (field[i+1][j+3] || field[i][j + 3] || field[i + 1][j + 2] || field[i + 1][j + 1] || field[i + 1][j])
              return false;
            continue;
          }
          des--;
          field[i][j + 1] = 0;
          field[i][j] = 0;
          if (field[i+1][j+2] || field[i][j + 2] || field[i + 1][j + 1] || field[i + 1][j])
            return false;
          continue;
        }
        if (field[i + 1][j])
        {
          if (field[i + 2][j])
          {
            if (field[i + 3][j])
            {
              bat--;
              field[i + 3][j] = 0;
              field[i + 2][j] = 0;
              field[i + 1][j] = 0;
              field[i][j] = 0;
              if (field[i+4][j+1]||field[i + 4][j] || field[i + 3][j + 1] || field[i + 2][j + 1] || field[i + 1][j + 1] || field[i][j + 1])
                return false;
              continue;
            }
            cruz--;
            field[i + 2][j] = 0;
            field[i + 1][j] = 0;
            field[i][j] = 0;
            if (field[i+3][j+1]||field[i + 3][j] || field[i + 2][j + 1] || field[i + 1][j + 1] || field[i][j + 1])
              return false;
            continue;
          }
          des--;
          field[i + 1][j] = 0;
          field[i][j] = 0;
          if (field[i+2][j+1]||field[i + 2][j] || field[i + 1][j + 1] || field[i][j + 1])
            return false;
          continue;
        }
        field[i][j] = 0;
        if (field[i + 1][j + 1] || field[i][j + 1])
          return false;
        sub--;
      }
    }
  }
  for (auto i = 0; i < 10; i++)
  {
    for (auto j = 0; j < 10; j++)
    {
      if (field[i][j])
        return false;
    }
  }
  if(sub == 0 && cruz == 0 && des == 0 && bat == 0)
    return true;
  return false;
}