// range extraction #include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
  std::string answer;

  if (args.size() == 1)
  {
    answer = answer + std::to_string(args[0]);
    return answer;
  }

  const int max = args.size();
  for (int i = 0; i < max; i++)
  {
    int current = args[i];

    if (i == max - 1)
    {
      answer = answer + std::to_string(args[i]);
      return answer;
    }
    else
    {
      for (int j = i + 1; j < max; j++)
      {
        
        if (args[j] == current + j - i)
        { 
          if(j!=max-1)continue;
          else {
            if (i == j-1) 
            {
              answer = answer + std::to_string(args[i]);
              answer.push_back(',');
              answer = answer + std::to_string(args[j]);
              return answer;
            }
            else
            {
              answer = answer + std::to_string(args[i]);
              answer.push_back('-');
              answer = answer + std::to_string(args[j]);
              return answer;
            }
          }
        }
        else
        {
          if (j == i + 1) answer = answer + std::to_string(args[i]);
          else if (j == i + 2)
          {
            answer = answer + std::to_string(args[i]);
            answer.push_back(',');
            answer = answer + std::to_string(args[i + 1]);
            i = j - 1;
          }
          else
          {
            answer = answer + std::to_string(args[i]);
            answer.push_back('-');
            answer = answer + std::to_string(args[j - 1]);
            i = j - 1;
          }
          break;
        }
      }
    }

    answer.push_back(',');
  }

  return answer;
}