//playing on a chessboard

using namespace std;
 
class Suite2
{
    public:
    static string game(unsigned long long n){
      if(n == 0) return "[0]";
      string returned="[";
      unsigned long long result{0};
      long current{1};
      for(unsigned long long i{0};i<n-1;i++){
        result += current;
        current += 1;
      }
      if(current%2 == 1){
        result = result*2 + current;
        returned += to_string(result)+", 2]";
        return returned;
      }else{
        result += current/2;
        returned += to_string(result)+"]";
        return returned;
      }
    }
};