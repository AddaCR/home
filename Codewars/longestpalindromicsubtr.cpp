//longest palindromic substring

#include<iostream>
#include<string>
#include<map>

using namespace std;

string longest_palindrome(string input)
{
    int size = input.size();
    if (size == 0)
        return "";
    string result;
    int length = 1;
    for (int i = 1; i < size; i++)
    {
        int j = 1, g = 0;
        while (input[i - j] == input[i + j])
        {
             if (input[i - j] == input[i + j])
            {
                j++;
            }
             if (i - j < 0 || i + j >= size)
                 break;
        }
        while ( input[i - g - 1] == input[i + g])
        {
            if (input[i - g - 1] == input[i + g])
            {
                g++;
            }
            if (i - g - 1 < 0 || i + g >= size)
                break;
        }
        if ((2 * j) - 1 > length)
        {
            string res;
            for (int n = -j + 1; n < j; n++)
            {
                res.push_back(input[i + n]);
            }
            length = res.size();
            result = res;
        }
        if (2 * g > length)
        {
            string res;
            for (int n = -g; n < g; n++)
            {
                res.push_back(input[i + n]);
            }
            length = res.size();
            result = res;
        }
    }
    if (length == 1)
    {
        result.push_back(input[0]);
        return result;
    }

    return result;
}