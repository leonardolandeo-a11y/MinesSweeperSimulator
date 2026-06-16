#include <bits/stdc++.h>
#include <ncurses.h>
#include <random>

using namespace std;

int ActivateBoom(int n, int m){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0,(n*m));
    return dist(gen);
}
class Board{
private:
    int m;
    int n;
    bool boom;
    vector<vector<char>> boardMatrix;
    vector<vector<bool>> MapBoom;

public:
    Board(int m, int n)
    :m(m),n(n), boom(false), boardMatrix(m,vector<char>(n)), MapBoom(m,vector<bool>(n)){};

    void CreateBoard(){
        for(int i =0;i <m ;i++){
            for (int j = 0; j<n;j++){
                int randomNumber = ActivateBoom(this->n, this->m);
                if (randomNumber == i || randomNumber == j){
                    this->boom = true;
                }else{
                    this->boom = false;
                }
                boardMatrix[i][j] = '#';
                MapBoom[i][j] = boom;
            }
        }
    }

    void ShowBoard(){
        for (int i = 0 ; i < m; i ++){
            for (int j = 0; j <n; j++){
                char element = boardMatrix[i][j];
                mvprintw(i,j,"%c",element);
            }
        }
        refresh();
    }

    ~Board(){}


};

class Player{
private:
    int column_x;
    int row_y;
    char shape;
public:
    Player(int column_x,int row_y, char shape)
    : column_x(column_x),row_y(row_y),shape(shape){};
    const int& getX() const{
        return column_x;
    }
    const int& getY() const{
        return row_y;
    }
    void setX(int column_x){
        this->column_x = column_x;
    }
    void setY(int row_y){
        this->row_y = row_y;
    }
    void ShowPlayer(){
        mvprintw(row_y,column_x,"%c",shape);
    }

};

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);

    // Size of the board
    const int m = 10;
    const int n = 10;
    

    Board* BoardGame = new Board(m,n);
    Player* PlayerGame = new Player(0,0, '@');


    BoardGame->CreateBoard();
    BoardGame->ShowBoard();

    while(true){
        clear();
        int column_x = PlayerGame->getX();
        int row_y = PlayerGame->getY();
        BoardGame->ShowBoard();
        PlayerGame->ShowPlayer();
        refresh();
        int key = getch();
        
        if (key == KEY_UP && row_y > 0){
            PlayerGame->setY(row_y - 1);
        }

        if (key == KEY_DOWN && row_y < m - 1){
            PlayerGame->setY(row_y + 1);
        }

        if (key == KEY_LEFT && column_x > 0){
            PlayerGame->setX(column_x - 1);
        }

        if (key == KEY_RIGHT && column_x < n - 1){
            PlayerGame->setX(column_x + 1);
        }



    }
    endwin();
    return 0;
}