#include <bits/stdc++.h>
#include <ncurses.h>
#include <random>
#include "Board.h"
#include "Player.h"
#include "Cell.h"
using namespace std;



int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    srand(time(0));
    

    Board* BoardGame = new Board(m,n);
    Player* PlayerGame = new Player(0,2, '@');
    int level = 40;
    BoardGame->PlaceBombs(level);
    BoardGame->CalculateAdjacentBombs();
    
    while(true){
        clear();
        BoardGame->ShowBoard();
        PlayerGame->ShowPlayer();
        refresh();
        if (!PlayerGame->Move(BoardGame)){
            clear();
            mvprintw(10, 5, "GAME OVER!");
            refresh();
            getch();      
            break;
        };
        

        
        
    }
    endwin();
    return 0;
}