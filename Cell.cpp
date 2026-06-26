#include "Cell.h"


Cell::Cell()
:bomb(false), revealed(false),flagged(false),adjacentBombs(0){};

bool Cell::getBomb(){
    return bomb;
}
bool Cell::getRevealed(){
    return revealed;
}
bool Cell::getFlagged(){
    return flagged;
}
int Cell::getAdjacentBombs(){
    return adjacentBombs;
}
void Cell::setBombs(bool bomb){
    this->bomb = bomb;
}
void Cell::setReveal(){
    revealed = true;
}
void Cell::setFlag(){
    flagged = !flagged;
}
void Cell::setAdjacentBombs(int bombs){
    adjacentBombs = bombs;
}