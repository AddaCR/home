// permutations

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<string> &result,const string &s,string &re,int numOfLevel,int rangeOfLevel,bool *tag)
{
  if(numOfLevel==rangeOfLevel)
  {
    result.push_back(re);
    return;
  }
  for(int i = 0; i < s.length(); i++)
  {
    if(tag[i])
      continue;
    re[numOfLevel] = s[i];
    tag[i] = true;  //lock
    dfs(result,s,re,numOfLevel+1,rangeOfLevel,tag);
    tag[i] = false;
  }
}

vector<string> permutations(string s) {
  vector<string> result;
  string re = s;
  bool *tag = new bool[s.size()];
  for(int i = 0; i<s.length(); i++)
    tag[i] = false;
  dfs(result,s,re,0,s.size(),tag);
  sort(result.begin(),result.end());
  result.erase(unique(result.begin(),result.end()),result.end());
  delete[] tag;
  return result;
}