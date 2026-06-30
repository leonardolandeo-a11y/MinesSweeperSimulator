#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
using namespace std;


class HumanPlayer:public Player{
public: 
    HumanPlayer(int x, int y, char shape);
    bool Move(Board* board) override;
    ~HumanPlayer();
};


#endif