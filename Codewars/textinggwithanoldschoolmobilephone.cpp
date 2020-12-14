//texting with an old-school phone

#include <string>

using namespace std;

string send_message(const string& message)
{
  string result;
  int index = -1;
  for (auto& ch : message)
  {
    index++;
    if (isupper(ch) && index == 0)result += '#';
    if (islower(ch) && index > 0)
    {
      for (int i = index - 1; i >= 0; i--)
      {
        if (isalpha(message[i]))
        {
          if (isupper(message[i]))
          {
            result += '#';
            break;
          }
          else break;
        }
      }
    }
    if (isupper(ch) && index > 0)
    {
      for (int i = index - 1; i >= 0; i--)
      {
        if (isalpha(message[i]))
        {
          if (islower(message[i]))
          {
            result += '#';
            break;
          }
          else break;
        }
        if (!isalpha(message[i]) && i == 0)
        {
          result += '#';
          break;
        }
      }
    }
    switch (ch)
    {
    case 'A':
    case 'a':
      if (message[index + 1] == '2')
      {
        result += "2 ";
        break;
      }
      if (tolower(message[index + 1]) == 'a' || tolower(message[index + 1]) == 'b' || tolower(message[index + 1]) == 'c')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "2 ";
        else result += "2";
      }
      else result += '2';
      break;
    case 'B':
    case 'b':
      if (message[index + 1] == '2')
      {
        result += "22 ";
        break;
      }
      if (tolower(message[index + 1]) == 'a' || tolower(message[index + 1]) == 'b' || tolower(message[index + 1]) == 'c')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "22 ";
        else result += "22";
      }
      else result += "22";
      break;
    case 'C':
    case 'c':
      if (message[index + 1] == '2')
      {
        result += "222 ";
        break;
      }
      if (tolower(message[index + 1]) == 'a' || tolower(message[index + 1]) == 'b' || tolower(message[index + 1]) == 'c')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "222 ";
        else result += "222";
      }
      else result += "222";
      break;
    case 'D':
    case 'd':
      if (message[index + 1] == '3')
      {
        result += "3 ";
        break;
      }
      if (tolower(message[index + 1]) == 'd' || tolower(message[index + 1]) == 'e' || tolower(message[index + 1]) == 'f')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "3 ";
        else result += "3";
      }
      else result += "3";
      break;
    case 'E':
    case 'e':
      if (message[index + 1] == '3')
      {
        result += "33 ";
        break;
      }
      if (tolower(message[index + 1]) == 'd' || tolower(message[index + 1]) == 'e' || tolower(message[index + 1]) == 'f')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "33 ";
        else result += "33";
      }
      else result += "33";
      break;
    case 'F':
    case 'f':
      if (message[index + 1] == '3')
      {
        result += "333 ";
        break;
      }
      if (tolower(message[index + 1]) == 'd' || tolower(message[index + 1]) == 'e' || tolower(message[index + 1]) == 'f')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "333 ";
        else result += "333";
      }
      else result += "333";
      break;
    case 'G':
    case 'g':
      if (message[index + 1] == '4')
      {
        result += "4 ";
        break;
      }
      if (tolower(message[index + 1]) == 'g' || tolower(message[index + 1]) == 'h' || tolower(message[index + 1]) == 'i')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "4 ";
        else result += "4";
      }
      else result += "4";
      break;
    case 'H':
    case 'h':
      if (message[index + 1] == '4')
      {
        result += "44 ";
        break;
      }
      if (tolower(message[index + 1]) == 'g' || tolower(message[index + 1]) == 'h' || tolower(message[index + 1]) == 'i')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "44 ";
        else result += "44";
      }
      else result += "44";
      break;
    case 'I':
    case 'i':
      if (message[index + 1] == '4')
      {
        result += "444 ";
        break;
      }
      if (tolower(message[index + 1]) == 'g' || tolower(message[index + 1]) == 'h' || tolower(message[index + 1]) == 'i')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "444 ";
        else result += "444";
      }
      else result += "444";
      break;
    case 'J':
    case 'j':
      if (message[index + 1] == '5')
      {
        result += "5 ";
        break;
      }
      if (tolower(message[index + 1]) == 'j' || tolower(message[index + 1]) == 'k' || tolower(message[index + 1]) == 'l')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "5 ";
        else result += "5";
      }
      else result += "5";
      break;
    case 'K':
    case 'k':
      if (message[index + 1] == '5')
      {
        result += "55 ";
        break;
      }
      if (tolower(message[index + 1]) == 'j' || tolower(message[index + 1]) == 'k' || tolower(message[index + 1]) == 'l')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "55 ";
        else result += "55";
      }
      else result += "55";
      break;
    case 'L':
    case 'l':
      if (message[index + 1] == '5')
      {
        result += "555 ";
        break;
      }
      if (tolower(message[index + 1]) == 'j' || tolower(message[index + 1]) == 'k' || tolower(message[index + 1]) == 'l')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "555 ";
        else result += "555";
      }
      else result += "555";
      break;
    case 'M':
    case 'm':
      if (message[index + 1] == '6')
      {
        result += "6 ";
        break;
      }
      if (tolower(message[index + 1]) == 'm' || tolower(message[index + 1]) == 'n' || tolower(message[index + 1]) == 'o')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "6 ";
        else result += "6";
      }
      else result += "6";
      break;
    case 'N':
    case 'n':
      if (message[index + 1] == '6')
      {
        result += "66 ";
        break;
      }
      if (tolower(message[index + 1]) == 'm' || tolower(message[index + 1]) == 'n' || tolower(message[index + 1]) == 'o')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "66 ";
        else result += "66";
      }
      else result += "66";
      break;
    case 'O':
    case 'o':
      if (message[index + 1] == '6')
      {
        result += "666 ";
        break;
      }
      if (tolower(message[index + 1]) == 'm' || tolower(message[index + 1]) == 'n' || tolower(message[index + 1]) == 'o')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "666 ";
        else result += "666";
      }
      else result += "666";
      break;
    case 'P':
    case 'p':
      if (message[index + 1] == '7')
      {
        result += "7 ";
        break;
      }
      if (tolower(message[index + 1]) == 'p' || tolower(message[index + 1]) == 'q' || tolower(message[index + 1]) == 'r' || tolower(message[index + 1]) == 's')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "7 ";
        else result += "7";
      }
      else result += "7";
      break;
    case 'Q':
    case 'q':
      if (message[index + 1] == '7')
      {
        result += "77 ";
        break;
      }
      if (tolower(message[index + 1]) == 'p' || tolower(message[index + 1]) == 'q' || tolower(message[index + 1]) == 'r' || tolower(message[index + 1]) == 's')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "77 ";
        else result += "77";
      }
      else result += "77";
      break;
    case 'R':
    case 'r':
      if (message[index + 1] == '7')
      {
        result += "777 ";
        break;
      }
      if (tolower(message[index + 1]) == 'p' || tolower(message[index + 1]) == 'q' || tolower(message[index + 1]) == 'r' || tolower(message[index + 1]) == 's')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "777 ";
        else result += "777";
      }
      else result += "777";
      break;
    case 'S':
    case 's':
      if (message[index + 1] == '7')
      {
        result += "7777 ";
        break;
      }
      if (tolower(message[index + 1]) == 'p' || tolower(message[index + 1]) == 'q' || tolower(message[index + 1]) == 'r' || tolower(message[index + 1]) == 's')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "7777 ";
        else result += "7777";
      }
      else result += "7777";
      break;
    case 'T':
    case 't':
      if (message[index + 1] == '8')
      {
        result += "8 ";
        break;
      }
      if (tolower(message[index + 1]) == 't' || tolower(message[index + 1]) == 'u' || tolower(message[index + 1]) == 'v')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "8 ";
        else result += "8";
      }
      else result += "8";
      break;
    case 'U':
    case 'u':
      if (message[index + 1] == '8')
      {
        result += "88 ";
        break;
      }
      if (tolower(message[index + 1]) == 't' || tolower(message[index + 1]) == 'u' || tolower(message[index + 1]) == 'v')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "88 ";
        else result += "88";
      }
      else result += "88";
      break;
    case 'V':
    case 'v':
      if (message[index + 1] == '8')
      {
        result += "888 ";
        break;
      }
      if (tolower(message[index + 1]) == 't' || tolower(message[index + 1]) == 'u' || tolower(message[index + 1]) == 'v')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "888 ";
        else result += "888";
      }
      else result += "888";
      break;
    case 'W':
    case 'w':
      if (message[index + 1] == '9')
      {
        result += "9 ";
        break;
      }
      if (tolower(message[index + 1]) == 'w' || tolower(message[index + 1]) == 'x' || tolower(message[index + 1]) == 'y' || tolower(message[index + 1]) == 'z')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "9 ";
        else result += "9";
      }
      else result += "9";
      break;
    case 'X':
    case 'x':
      if (message[index + 1] == '9')
      {
        result += "99 ";
        break;
      }
      if (tolower(message[index + 1]) == 'w' || tolower(message[index + 1]) == 'x' || tolower(message[index + 1]) == 'y' || tolower(message[index + 1]) == 'z')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "99 ";
        else result += "99";
      }
      else result += "99";
      break;
    case 'Y':
    case 'y':
      if (message[index + 1] == '9')
      {
        result += "999 ";
        break;
      }
      if (tolower(message[index + 1]) == 'w' || tolower(message[index + 1]) == 'x' || tolower(message[index + 1]) == 'y' || tolower(message[index + 1]) == 'z')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "999 ";
        else result += "999";
      }
      else result += "999";
      break;
    case 'Z':
    case 'z':
      if (message[index + 1] == '9')
      {
        result += "9999 ";
        break;
      }
      if (tolower(message[index + 1]) == 'w' || tolower(message[index + 1]) == 'x' || tolower(message[index + 1]) == 'y' || tolower(message[index + 1]) == 'z')
      {
        if (islower(ch) && islower(message[index + 1]) || isupper(ch) && isupper(message[index + 1]))
          result += "9999 ";
        else result += "9999";
      }
      else result += "9999";
      break;
    case ' ':
      if (message[index + 1] == ' ')result += "0 ";
      else result += "0";
      break;
    case '.':
      if (message[index + 1] == '1')
      {
        result += "1 ";
        break;
      }
      if (message[index + 1] == '.' || message[index + 1] == ',' || message[index + 1] == '?' || message[index + 1] == '!')result += "1 ";
      else result += "1";
      break;
    case ',':
      if (message[index + 1] == '1')
      {
        result += "11 ";
        break;
      }
      if (message[index + 1] == '.' || message[index + 1] == ',' || message[index + 1] == '?' || message[index + 1] == '!')result += "11 ";
      else result += "11";
      break;
    case '?':
      if (message[index + 1] == '1')
      {
        result += "111 ";
        break;
      }
      if (message[index + 1] == '.' || message[index + 1] == ',' || message[index + 1] == '?' || message[index + 1] == '!')result += "111 ";
      else result += "111";
      break;
    case '!':
      if (message[index + 1] == '1')
      {
        result += "1111 ";
        break;
      }
      if (message[index + 1] == '.' || message[index + 1] == ',' || message[index + 1] == '?' || message[index + 1] == '!')result += "1111 ";
      else result += "1111";
      break;
    case '\'':
      if (message[index + 1] == '*')
      {
        result += "* ";
        break;
      }
      if (message[index + 1] == '\'' || message[index + 1] == '-' || message[index + 1] == '+' || message[index + 1] == '=')result += "* ";
      else result += "*";
      break;
    case '-':
      if (message[index + 1] == '*')
      {
        result += "** ";
        break;
      }
      if (message[index + 1] == '\'' || message[index + 1] == '-' || message[index + 1] == '+' || message[index + 1] == '=')result += "** ";
      else result += "**";
      break;
    case '+':
      if (message[index + 1] == '*')
      {
        result += "*** ";
        break;
      }
      if (message[index + 1] == '\'' || message[index + 1] == '-' || message[index + 1] == '+' || message[index + 1] == '=')result += "*** ";
      else result += "***";
      break;
    case '=':
      if (message[index + 1] == '*')
      {
        result += "**** ";
        break;
      }
      if (message[index + 1] == '\'' || message[index + 1] == '-' || message[index + 1] == '+' || message[index + 1] == '=')result += "**** ";
      else result += "****";
      break;
    default:
      result += ch;
      result += '-';
      break;
    }
  }
  return result;
}