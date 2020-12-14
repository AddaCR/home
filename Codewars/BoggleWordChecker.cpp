//Boggle World Checker
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool find_first(vector<vector<char> > &board, const string &word, int &i, int &j)
{
  for (; i < board.size(); i++)
  {
    for (; j < board.size(); j++)
    {
      if (word[0] == board[i][j])
      {
        return true;
      }
    }
    j = 0;
  }
  return false;
}

bool mere(vector<vector<char>> &board, string& word, int row, int col, int curLetterIndex)
{
  if (curLetterIndex >= word.length())
  {
    return true;
  }
  if (row < 0 || col < 0)
  {
    return false;
  }
  if (row >= board.size() || col >= board.size())
  {
    return false;
  }
  if (board[row][col] != word[curLetterIndex])
  {
    return false;
  }
                           
  board[row][col] = tolower(board[row][col]); 

  int startI = std::max(0, row - 1);
  int startJ = std::max(0, col - 1);
  int endI = std::min(row + 2, (int)board.size());
  int endJ = std::min(col + 2, (int)board.size());

  for (auto i = startI; i < endI; i++)
  {
    for (int j = startJ; j < endJ; j++)
    {
      if (i == row && j == col)
        continue;
      if (mere(board, word, i, j, curLetterIndex + 1) == true)
        return true;
    }
  }

  board[row][col] = toupper(board[row][col]);
  return false;
}

bool check_word(const vector<vector<char> > &sourceBoard, const string &word)
{
  vector<vector<char>> board = sourceBoard;
  string world = word;
  int startRow = 0;
  int startCol = 0;
  int curLetterIndex = 0;

  if (word.length() == 1)
  {
    return find_first(board, world, startRow, startCol);
  }

  while (find_first(board, world, startRow, startCol) == true)
  {
    if (mere(board, world, startRow, startCol, curLetterIndex) == true)
    {
      return true;
    }
    startCol++;
  }

  return false;
}