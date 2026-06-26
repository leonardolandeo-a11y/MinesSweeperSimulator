#ifndef CELL_H
#define CELL_H


class Cell{
private:
    bool bomb;
    bool revealed;
    bool flagged;
    int adjacentBombs;

public:
    Cell();
    
    bool getBomb();
    bool getRevealed();
    bool getFlagged();
    int getAdjacentBombs();
    void setBombs(bool bomb);
    void setReveal();
    void setFlag();
    void setAdjacentBombs(int bombs);



};




#endif