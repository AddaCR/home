//Snail
#include <vector>

std::vector<int> snail(std::vector<std::vector<int>> snail_map) {
   int start = 0;
   int end = snail_map[0].size();
   
   if(end == 0)
   {
     return {};
   }
   
   std::vector<int> result;

   while (start < end) 
   {
      for (int i = start; i < end; ++i) 
      {
         result.push_back(snail_map[start][i]);
      }

      for (int i = start + 1; i < end; ++i) 
      {
         result.push_back(snail_map[i][end - 1]);
      }
      

      if (start < end) 
      {
         for (int i = end - 2; i >= start; --i) 
         {
            result.push_back(snail_map[end - 1][i]);
         }
         end--;
      }

      if (start < end) 
      {
         for (int i = end - 1; i >= start + 1; --i) 
         {
            result.push_back(snail_map[i][start]);
         }
         start++;
      }
   }
   return result;
}