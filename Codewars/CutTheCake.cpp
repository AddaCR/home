// Cut the cake
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*

NOTE : You are provided with these functions

std::string join(const std::string &sep, const std::vector<std::string> &to_join)

std::vector<std::string> split(const std::string &to_split, char separator = '\n')
*/

void cuttheslice(vector<string> &aux, int upi, int upj, int height, int width)
{
  for (auto ii = upi; ii < height + upi; ii++)
  {
    for (auto jj = upj; jj < upj + width; jj++)
    {
      if (aux[ii][jj] == '.')
      {
        aux[ii][jj] = '0';
      }
      if (aux[ii][jj] == 'o')
      {
        aux[ii][jj] = '1';
      }
    }
  }
  return;
}

string slice(const vector<string> &aux, int height, int width, int upi, int upj, int length)
{
  int len = 0, countR = 0;
  string slicee;
  for (auto i = upi; i < height + upi && i < aux.size(); i++)
  {
    for (auto j = upj; j < width + upj && j < aux[0].length(); j++)
    {
      if (aux[i][j] == '0' || aux[i][j] == '1')
      {
        return {};
      }

      if (aux[i][j] == '.')
      {
        len++;
        slicee.append(".");
      }

      if (aux[i][j] == 'o')
      {
        len++;
        countR++;
        slicee.append("o");
      }

      if (countR > 1)
      {
        return {};
      }
      if (len == length)
      {
        break;
      }
    }

    slicee.append("\n");

    if (len == length)
    {
      break;
    }
  }

  if (countR != 1)
    return {};
  if (len != length)
    return {};
  slicee = slicee.substr(0, slicee.length() - 1);
  return slicee;
}


void findij(int &upi, int &upj, const vector<string> &aux)
{
  for (auto i = 0; i < aux.size(); i++)
  {
    size_t found = aux[i].find_first_not_of("01");
    if (found != std::string::npos)
    {
      upi = i;
      upj = found;
      return;
    }
  }
  return;
}

void reverseme(vector<string> &caux, int upi, int upj, int height, int width)
{
  for (auto ii = upi; ii < height + upi; ii++)
  {
    for (auto jj = upj; jj < upj + width; jj++)
    {
      if (caux[ii][jj] == '0')
      {
        caux[ii][jj] = '.';
      }
      if (caux[ii][jj] == '1')
      {
        caux[ii][jj] = 'o';
      }
    }
  }
  return;
}


void makeSlices(vector<string> &caux, int nLengths, vector<string> &result, int nRaisins, const vector<string> &aux)
{
  string slicee;
  int upi = 0, upj = 0, width, height;
  findij(upi, upj, caux);
  
  for (width = caux[0].length(); width >= 1; width--)
  {
    for (height = 1; height <= caux.size(); height++)
    {
      if ((height * width) != nLengths)
        continue;
      slicee = slice(caux, height, width, upi, upj, nLengths);
      if (!slicee.length())
        continue;
      result.push_back(slicee);
      cuttheslice(caux, upi, upj, height, width);

      makeSlices(caux, nLengths, result, nRaisins, aux);


      if (result.size() == nRaisins)
        return;
      else
      {
        reverseme(caux, upi, upj, height, width);
        result.pop_back();

      }
    }
  }
  return;
}

void hei(vector<string> &caux, int nLengths, vector<string> &result, int nRaisins, vector<string> &aux)
{
  string slicee;
  int upi = 0, upj = 0, contor = 0;
  findij(upi, upj, caux);
  
  int width = caux[0].length();
  int height = 1;

  makeSlices(caux, nLengths, result, nRaisins, aux);

  if(result.size() != nRaisins)
  


  return;

}

std::vector<std::string> matrix(const std::string &cake)
{
  int start = 0;
  vector<string> aux;
  for (auto a = 0; a != cake.length(); a++)
  {
    if (cake[a] == '\n')
    {
      aux.push_back(cake.substr(start, a - start));
      start = a + 1;
    }

    if (a + 1 == cake.length())
    {
      aux.push_back(cake.substr(start, a - start + 1));
      break;
    }
  }
  return aux;
}

void checkResult(vector<string> &result, int nLengths)
{
  int area = 0, nRaisins = 0;
  for (auto i = 0; i < result.size(); i++)
  {
    for(auto j = 0; j < result[i].length(); j++)
    {
      if (result[i][j] == '.')
      {
        area++;
      }

      if (result[i][j] == 'o')
      {
        area++;
        nRaisins++;
      } 
    }

    if (area != nLengths)
    {
      result.clear();
      return;
    }

    if (nRaisins > 1)
    {
      result.clear();
      return;
    }

    area = 0;
    nRaisins = 0;
  }
}

bool checkaux(const vector<string> &aux)
{
  for (int i = 0; i < aux.size(); i++)
  {
    for (int j = 0; j < aux[i].length(); j++)
    {
      if (aux[i][j] != 0)
        return false;
    }
  }
  return true;
}

std::vector<std::string> cut(const std::string &cake)
{
  int nRaisins = count(cake.begin(), cake.end(), 'o');
  int naux = cake.length() - count(cake.begin(), cake.end(), '\n');
  if (nRaisins == 0 || ((naux % nRaisins) != 0))
  {
    return {};
  }
  int nLengths = naux / nRaisins;

  std::vector<std::string> aux = matrix(cake);

  vector<string> result;

  vector<string> caux = aux;
  hei(caux, nLengths, result, nRaisins, aux);

  return result;

}