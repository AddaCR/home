//shortest knight path

#include <string>
#include <iostream>

struct Position
{
  int x, y;
  Position(int posX, int posY):
    x(posX), y(posY) {}
  Position(std::string posStr):
    Position(0, 0)
  {
      if (posStr.length() != 2)
        return;
      
      x = posStr[1] - '1';
      y = posStr[0] - 'a';
  }  
  bool IsValid()
  {
    return ((x >= 0) && (x <= 7)) && ((y >= 0) && (y <= 7));
  }
  bool operator==(const Position& pos2)
  {
    return (x == pos2.x) && (y == pos2.y);
  }
  void operator+=(const Position& pos2)
  {
    x += pos2.x;
    y += pos2.y;
  }
};

int computeNrMoves(Position cur, const Position& fin, int moveNumber)
{
  if (cur == fin)
    return moveNumber;
  
  if (moveNumber > 5)
    return 6;
  
  int lowestAvailableMoveCount = 6;
  
  for (int i = 0; i < 8; i++)
  {
    Position move((i % 2) + 1, ((i + 1) % 2) + 1);
    
    if (i >= 4)
      move.y *= -1;
    if ((i % 4) >= 2)
      move.x *= -1;
    
    move += cur;
   
    if (!move.IsValid())
      continue;
   
    
    int moveCountWithThisPath = computeNrMoves(move, fin, moveNumber + 1);
    if (moveCountWithThisPath < lowestAvailableMoveCount)
      lowestAvailableMoveCount = moveCountWithThisPath;
  }
  
  return lowestAvailableMoveCount;
}

int knight(std::string start, std::string finish) {
  return computeNrMoves(Position(start), Position(finish), 0);
}