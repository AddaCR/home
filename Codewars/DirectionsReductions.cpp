//Directions Reduction

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
    
};

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr)
{
   int length = arr.size();
   while (true)
   {
      bool change = false;
      for (auto i = 0; i < length - 1; i++)
      {
         if ((arr[i] == "SOUTH" && arr[i + 1] == "NORTH") ||
            (arr[i] == "NORTH" && arr[i + 1] == "SOUTH") ||
            (arr[i] == "EAST" && arr[i + 1] == "WEST") ||
            (arr[i] == "WEST" && arr[i + 1] == "EAST"))
         {
            arr.erase(arr.begin() + i, arr.begin() + i + 2);
            i--;
            length -= 2;
            change = true;
         }
      }
      if (change == false)
         break;
   }

   return arr;
}