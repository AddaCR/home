//counting change combinations

#include <vector>
using namespace std;
unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins) {
  size_t len = coins.size();
  vector<vector<long>> dp(len, vector<long>(money+1,0));
  vector<unsigned int> coin(coins);
  sort(coin.begin(),coin.end());
  for(int i=0;i<len;i++){
    dp[i][0]=1;
  }
  for(int i=1;i<=money;i++){
    if(i%coin[0]==0){
      dp[0][i]=1;
    }else{
      dp[0][i]=0;
    }
  }
  for(int i=1;i<len;i++){
    for(int j=1;j<=money;j++){
      dp[i][j]=dp[i-1][j];
      if(j-(int)coin[i]>=0){
        dp[i][j]+=dp[i][j-(int)coin[i]];
      }
    }
  } 
   return dp[len-1][money];
}