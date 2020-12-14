//complete binary tree
#include <vector>
#include <iostream>

using namespace std;

vector<int> calcTree(int node, int num) {
  vector<int> res;
  if(node <= num) {
    res = calcTree(2*node, num);
    res.push_back(node);
    auto right = calcTree(2*node+1, num);
    copy(right.begin(), right.end(), back_inserter(res));
  }
  return res;
}

vector<int> complete_binary_tree(const vector<int>& input){
  vector<int> tree = calcTree(1,input.size());
  vector<int> result(input.size());
  for(vector<int>::size_type i=0; i<input.size(); ++i){
    if(tree[i]-1 < result.size()){
      result[tree[i]-1] = input[i];
    }
  }
  return result;
}