//sum by factors

#include <string>
#include <vector>
#include <unordered_map> 
#include <map> 
#include <iostream>
using namespace std;

class SumOfDivided
{
public:
    static string sumOfDivided(vector<int> &lst);
  
    static void primeFactors(int n,unordered_map<int,int> &primes);
};
void SumOfDivided::primeFactors(int n,unordered_map<int,int> &primes) 
{ 
    int num=n;
    if(n<0) n= -n;
    unordered_map<int,int> tmp;
    while (n%2 == 0) 
    { 
        tmp[2]++; 
        n = n/2; 
    } 
    for (int i = 3; i*i <= n; i = i+2) 
    { 
        while (n%i == 0) 
        { 
          tmp[i]++;  
            n = n/i; 
        } 
    } 
    if (n > 2) 
        tmp[n]++;  
    unordered_map<int, int>:: iterator p; 
  for (p = tmp.begin(); p != tmp.end(); p++) 
    primes[p->first]+=num;
} 

string SumOfDivided::sumOfDivided(vector<int> &lst){
  
  unordered_map<int,int> primes;
  
  for(int i=0;i<lst.size();i++)
    primeFactors(lst[i],primes);
  
  string solut="";
  map<int, int> sol; 
  unordered_map<int, int>:: iterator p; 
  for (p = primes.begin(); p != primes.end(); p++) 
      sol.insert(pair<int, int>(p->first, p->second)); 
  
  map<int, int>::iterator itr; 
    
  for (itr = sol.begin(); itr != sol.end(); ++itr) 
    solut+=  "("+ to_string(itr->first) + " "  + to_string(itr->second) + ")"; 
    
  return solut;
  
}