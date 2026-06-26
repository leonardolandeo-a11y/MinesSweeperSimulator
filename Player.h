#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>
#include "Board.h"
using namespace std;

class Player{
private:
    int column_x;
    int row_y;
    char shape;
public:
    Player(int column_x,int row_y, char shape);
    const int& getX() const;
    const int& getY() const;
    void setX(int column_x);
    void setY(int row_y);
    void ShowPlayer();

    bool Move(Board* board);

};


#endif