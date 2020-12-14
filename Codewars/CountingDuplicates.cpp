//Counting Dublicates

size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
   int count = 0;
   std::vector<char> no;
   std::string str(in);
   int length = str.size();
   for (int i = 0; i < length; i++)
   {
      for (int j = i + 1; j < length; j++)
      {
         auto it = find(no.begin(), no.end(), tolower(str[i]));
            if (!no.empty() && it != no.end())
               continue;

         if (tolower(str[i]) == tolower(str[j]))
         {

            count++;
            no.push_back(tolower(str[i]));
            break;
         }
      }
   }
   return count;
}