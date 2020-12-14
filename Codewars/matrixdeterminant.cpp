//matrix determinant

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long determinant(vector< vector<long long> > m) {
  long long det = 0;
  if (m.size() == 1) {
    return m[0][0];
  }
  else if (m.size() == 2) {
    return m[0][0] * m[1][1] - 
           m[0][1] * m[1][0];
    
  }
  else if (m.size() > 2) {
  long long size = m[0].size();
  vector<vector<long long>> temp(size - 1, vector<long long> (size - 1, 0));
   for (long long x = 0; x < size; ++x) {
       long long subi = 0;
       for (long long i = 0; i < size; ++i) {
           if (i == 0) { 
				continue; 
				}
           long long subj = 0;
           for (long long j = 0; j < size; ++j) {
             if (x == j) { 
				continue; 
				}
             temp[subi][subj] = m[i][j];
             ++subj; 
           }
       ++subi;
       }
   det += (pow(-1, x) * m[0][x] * determinant(temp));
   }

   return det; 
  }
}