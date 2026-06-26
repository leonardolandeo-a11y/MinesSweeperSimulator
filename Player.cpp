#include "Player.h"

Player::Player(int column_x,int row_y, char shape)
: column_x(column_x),row_y(row_y),shape(shape){};

const int& Player::getX() const{
    return column_x;
}

const int& Player::getY() const{
    return row_y;
}

void Player::setX(int column_x){
    this->column_x = column_x;
}

void Player::setY(int row_y){
    this->row_y = row_y;
}

void Player::ShowPlayer(){
    mvprintw(row_y,column_x,"%c",shape);
}

bool Player::Move(Board* board){
    
    int column_x =getX();
    int row_y = getY();
    
    int key = getch();
    
    if (key == KEY_UP && row_y > 0){
        setY(row_y - 1);
    }

    if (key == KEY_DOWN && row_y < m - 1){
        setY(row_y + 1);
    }

    if (key == KEY_LEFT && column_x > 0){
        setX(column_x - 1);
    }

    if (key == KEY_RIGHT && column_x < n - 1){
        setX(column_x + 1);
    }
    if (key == 'f'){
        board->CreateFlag(getY(),getX());
    }
    if (key == ' '){
        return board->RevealCell(getY(),getX());
    }
    return true;
} 
