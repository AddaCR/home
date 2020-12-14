// snakes and ladders

#include <unordered_map>
#include <string>

class SnakesLadders
{
  public:
    SnakesLadders(){};
  
    void move_player(int& position, int const& steps)
    {
      position += steps;
      
      int const end_point{100};
      if (position > end_point)
      {
        int const bounce_back{position - end_point};
        position = end_point - bounce_back;
      }
      
      auto ladder_base = ladders.find(position);
      auto snake_head = snakes.find(position);
      
      if (ladder_base != ladders.end()) 
      {
        position = ladder_base->second;
      }
      else if (snake_head != snakes.end()) 
      {
        position = snake_head->second;
      }
    };
  
    std::string play(int die1, int die2)
    {
      if (p1.position == 100 || p2.position == 100)
      {
        return "Game over!";
      }
      
      std::string current_id{p1.id};
      int current_pos{p1.position};
      bool double_die{false};
      
      if (die1 == die2)
      {
        double_die = true;
      }
      
      if (p1.turn)
      {
        move_player(p1.position, die1 + die2);
        current_id = p1.id;
        current_pos = p1.position;
      }
      else
      {
        move_player(p2.position, die1 + die2);
        current_id = p2.id;
        current_pos = p2.position;
      }
      
      std::swap(p1.turn,p2.turn);
      if (double_die)
      {
        std::swap(p1.turn,p2.turn);
      }
      
      if (current_pos == 100)
      {
        return "Player " + current_id + " Wins!";
      }
      return "Player " + current_id + " is on square " +  std::to_string(current_pos);
    };
  
  private:
  
    struct player
    {
      std::string id;
      int position;
      bool turn;
    };
  
    player p1{"1",0,true};
    player p2{"2",0,false};
  
    std::unordered_map<int, int> ladders
    {
      {2,38},
      {7,14},
      {8,31},
      {15,26},
      {21,42},
      {28,84},
      {36,44},
      {51,67},
      {71,91},
      {78,98},
      {87,94}
    };
    
    std::unordered_map<int, int> snakes
    {
      {16,6},
      {46,25},
      {49,11},
      {62,19},
      {64,60},
      {74,53},
      {89,68},
      {92,88},
      {95,75},
      {99,80}
    };
  
};