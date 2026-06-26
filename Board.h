#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"
#include <ncurses.h>
#include <random>

using namespace std;
// Size of the board
const int m = 20;
const int n = 20;


class Board{
private:
    int m;
    int n;
    vector<vector<Cell>> BoardMatrix;

public:
    Board(int m, int n);

    void CalculateAdjacentBombs();
    void ShowBoard();
    void FloodFill(int i, int j);
    void CreateFlag(int i, int j);
    void PlaceBombs(int numberBombs);
    bool RevealCell(int i, int j);
    
    ~Board(){}


};



#endif