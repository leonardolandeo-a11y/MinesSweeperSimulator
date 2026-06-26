#include "Board.h"

Board::Board(int m, int n):m(m),n(n), BoardMatrix(m,vector<Cell>(n)){};

void Board::PlaceBombs(int numberBombs){
    int bombs = 0;

    while (bombs < numberBombs){

        int row = rand()%m;
        int col = rand()%n;

        if (!BoardMatrix[row][col].getBomb()){

            BoardMatrix[row][col].setBombs(true);
            bombs++;
        }
    }
}
void Board::CalculateAdjacentBombs(){
    for(int i = 0; i< m; i++){
        for (int j = 0; j< n;j++){
            if (BoardMatrix[i][j].getBomb() == false){
                int count = 0;
                if (i >= 1 && j >= 1){
                    if (BoardMatrix[i-1][j-1].getBomb()){
                        count++;
                    }
                }

                if (i >= 1){
                    if (BoardMatrix[i-1][j].getBomb()){
                        count++;
                    }
                }

                if (i >= 1 && j < n-1){
                    if (BoardMatrix[i-1][j+1].getBomb()){
                        count++;
                    }
                }

                if (j >= 1){
                    if (BoardMatrix[i][j-1].getBomb()){
                        count++;
                    }
                }

                if (j < n-1){
                    if (BoardMatrix[i][j+1].getBomb()){
                        count++;
                    }
                }

                if (i < m-1 && j >= 1){
                    if (BoardMatrix[i+1][j-1].getBomb()){
                        count++;
                    }
                }

                if (i < m-1){
                    if (BoardMatrix[i+1][j].getBomb()){
                        count++;
                    }
                }

                if (i < m-1 && j < n-1){
                    if (BoardMatrix[i+1][j+1].getBomb()){
                        count++;
                    }
                }
                BoardMatrix[i][j].setAdjacentBombs(count);
                }
                

            }
            

        }
    }
void Board::ShowBoard(){

    for (int i = 0; i< m; i++){
        for(int j= 0; j<n;j++){
            if(BoardMatrix[i][j].getFlagged()){
                mvprintw(i,j,"%c",'F');
            }
            else if (!BoardMatrix[i][j].getRevealed()){
                mvprintw(i,j,"%c",'#');
            }
            else if (BoardMatrix[i][j].getBomb()){
                mvprintw(i,j,"%c",'X');
            }
            else{
                mvprintw(i,j,"%d",BoardMatrix[i][j].getAdjacentBombs());
            }

        }
    }
    refresh();
}

void Board::FloodFill(int i, int j){
    if (i < 0 || i >= m || j < 0 || j >= n){
        return;
    }
    if (BoardMatrix[i][j].getRevealed()== true){
        return;
    }
    if (BoardMatrix[i][j].getFlagged() == true){
        return;
    }
    if (BoardMatrix[i][j].getBomb() == true){
        return;
    }
    BoardMatrix[i][j].setReveal();
    if (BoardMatrix[i][j].getAdjacentBombs()>0){
        return;
    }
    FloodFill(i-1,j-1);
    FloodFill(i-1,j);
    FloodFill(i-1,j+1);
    FloodFill(i,j-1);
    FloodFill(i,j+1);
    FloodFill(i+1,j-1);
    FloodFill(i+1,j);
    FloodFill(i+1,j+1);


}
void Board::CreateFlag(int i, int j){
    if (!BoardMatrix[i][j].getRevealed()){
        BoardMatrix[i][j].setFlag();
    }
    
}

bool Board::RevealCell(int i, int j){
    if (BoardMatrix[i][j].getFlagged()){
        return true;   
    }

    if (BoardMatrix[i][j].getBomb()){
        return false;   
    }

    FloodFill(i,j);
    return true;
}
