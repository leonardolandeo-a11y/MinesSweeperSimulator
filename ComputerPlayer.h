#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "Player.h"
using namespace std;
class ComputerPlayer: public Player{
public:
    ComputerPlayer(int x, int y, char shape);
    bool Move(Board *Board) override;
    ~ComputerPlayer(){};
};


#endif