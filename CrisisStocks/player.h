#ifndef PLAYER_H
#define PLAYER_H

#include "bet.h"



class Player
 public:
  String name;
  unsigned int score;
  List<Bet> bets;
};

#endif // PLAYER_H
