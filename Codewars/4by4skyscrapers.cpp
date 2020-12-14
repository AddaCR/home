//4 by 4 Skyscrappers

#include <iostream>  
#include <vector>    
#include <algorithm> 

using namespace std;
#define N 4

bool isSafe(int grid[N][N], int row,int col, int num);
bool solve(int grid[N][N], int row, int col);

void clean (int grid[N][N],int n);
void onlyfour(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left);
bool one_two(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left);
void one_three(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left);
void two_zero(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left);
void two_finder(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left);

int** SolvePuzzle (int *clues) {
  
int matrix [4][4]={{}};
int blocks [4][4];
vector<int> matrix_vec;
vector<int> c_up; vector<int> c_down;
vector<int> c_left; vector<int> c_right;

 for (int i=0;i<4;i++){
    for(int j=0; j<4; j++){matrix[i][j]=*clues; *clues++;}
 }

 for(int i=0; i<4; i++){
    for (unsigned long j=0; j<4; j++){blocks[i][j] = (rand()%1)+0;}}

    for (int i=0;i<4;i++){
    for(int j=0; j<4; j++){int a= matrix[i][j]; matrix_vec.push_back(a);}};

for (unsigned long i=0; i<matrix_vec.size(); i++){
    int b = matrix_vec[i];
    if(i>=0 && i<=3)     {c_up.push_back(b);}
    if(i>=4 && i<=7)     {c_right.push_back(b);}
    if(i>=8 && i<=11)    {c_down.push_back(b);}
    if (i>=12 && i <=15) {c_left.push_back(b);}
    }
 reverse(c_down.begin(), c_down.end());
 reverse(c_left.begin(), c_left.end());

    cerr << " Matrix of clues " << endl;
    for (int i=0;i<4;i++){
    for(int j=0; j<4; j++){cerr << matrix[i][j] << " ";}cerr << endl;}

  onlyfour(blocks, c_up,c_down,c_right, c_left);
  solve(blocks, 0, 0); clean(blocks,4);


if (one_two(blocks, c_up,c_down,c_right, c_left))
{
    solve(blocks, 0, 0); clean(blocks,3);
}
else
{
       one_three(blocks, c_up,c_down,c_right, c_left);
       two_zero(blocks, c_up,c_down,c_right, c_left);
       solve(blocks, 0, 0); clean(blocks,3);
}

two_finder(blocks, c_up,c_down,c_right, c_left);
solve(blocks, 0, 0);

    cerr << " Solution  " << endl;
    for(int i=0; i<4; i++){
    for (int j=0; j<4; j++){cerr <<  blocks[i][j] << " ";}cerr<< endl;}

    int **tmpVar;
    tmpVar = new int*[4];
    for(int i=0;i<4;i++)
        tmpVar[i] = new int[4];

    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
        tmpVar[i][j] = blocks[i][j];

    return tmpVar;
}

bool isSafe(int grid[N][N], int row,int col, int num)
{
    for (int x = 0; x <= 3; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x <= 3; x++)
        if (grid[x][col] == num)
            return false;

    int startRow = row - row % 2,
            startCol = col - col % 2;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}
bool solve(int grid[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return true;
    if (col == N) {row++;col = 0;}

    if (grid[row][col] > 0)
        return solve(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solve(grid, row, col + 1))
            return true;
        }
        grid[row][col] = 0;
    }
    return false;
}
void onlyfour(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left)
{
    for(int i=0; i<4; i++){
    for (int j=0; j<4; j++){

      if (up[j]==1){
          bool d = true; int row =i; int col =j;
          for (int k=0;k<4;k++){if (grid[k][col]==4) {d=false;}if (grid[row][k]==4) {d=false;}}if(d==true){grid[0][j]=4;}}

      if (right[i]==1){
          bool d = true; int row =i; int col =j;
          for (int k=0;k<4;k++){if (grid[k][col]==4) {d=false;}if (grid[row][k]==4) {d=false;}}if(d==true){grid[i][3]=4;}}

     if (down[j]==1){
          bool d = true; int row =i; int col =j;
          for (int k=0;k<4;k++){if (grid[k][col]==4) {d=false;}if (grid[row][k]==4) {d=false;}}if(d==true){grid[3][j]=4;}}

     if (left[i]==1){
          bool d = true; int row =i; int col =j;
          for (int k=0;k<4;k++){if (grid[k][col]==4) {d=false;}if (grid[row][k]==4) {d=false;}}if(d==true){grid[i][0]=4;}}
 }
}
}
bool one_two(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left)
{
    bool r =false;
    for (int i=0; i<4; i++)
{
    if (up[i] == 1 && down[i]==2)    { r=true; grid[3][i]= 3; }
    if (left[i] == 2 && right[i]==1) { r=true; grid[i][0]= 3; }
    if (up[i] == 2 && down[i]==1)    { r=true; grid[0][i]= 3; }
    if (left[i] == 1 && right[i]==2) { r=true; grid[i][3]= 3; }
}
return r;
}
void one_three(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left)
{
    for (int i=0; i<4; i++)
{
    if (up[i] == 1 && down[i]==3)    { grid[2][i]= 3; }
    if (left[i] == 3 && right[i]==1) { grid[i][1]= 3; }
    if (up[i] == 3 && down[i]==1)    { grid[1][i]= 3; }
    if (left[i] == 1 && right[i]==3) { grid[i][2]= 3; }}
}
void clean (int grid[N][N],int n)
{
 if (n==4)
 {
    for(int i=0; i<4; i++){
    for (int j=0; j<4; j++){if (grid[i][j]==1 || grid[i][j]==2 || grid[i][j]==3 ){grid[i][j]=0;}}}
 }
 else
 {
    for(int i=0; i<4; i++){
    for (int j=0; j<4; j++){if (grid[i][j]==1 || grid[i][j]==2){grid[i][j]=0;}}}
 }

}

void two_finder(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left)
{
  for (int i =0; i <4; i++)
  {
    if (up[i]==2){if(grid[2][i]==4 && grid[3][i]==3){grid[0][i]=2; }}
    if (down[i]==2){if(grid[1][i]==4 && grid[0][i]==3){grid[3][i]=2;}}
    if (right[i]==2){if(grid[i][1]==4 && grid[i][0]==3){grid[i][3]=2;}}
    if (left[i]==2){if(grid[i][2]==4 && grid[i][3]==3){grid[i][0]=2;}}

    if (up[i]==3){if(grid[2][i]==4 && grid[3][i]==3){grid[1][i]=2;;}}
    if (down[i]==3){if(grid[1][i]==4 && grid[0][i]==3){grid[2][i]=2;}}
    if (right[i]==3){if(grid[i][1]==4 && grid[i][0]==3 ){grid[i][2]=2;}}
    if (left[i]==3){if(grid[i][2]==4 && grid[i][3]==3){grid[i][1]=2;}}



  }
}
void two_zero(int grid[N][N], vector<int> up,vector<int> down,vector<int> right, vector<int> left)
{
     for (int i =0; i <4; i++)
     {
      if (up[i]==2){if(grid[3][i]==4){grid[0][i]=3; }}
      if (down[i]==2){if(grid[0][i]==4){grid[3][i]=3;}}
      if (right[i]==2){if(grid[i][0]==4){grid[i][3]=3;}}
      if (left[i]==2){if(grid[i][3]==4){grid[i][0]=3;}}
     }
}