#include "Player.h"



/*
Constructor:
    -Columna_x -> coordenadas iniciales del jugador en las columnas de la matriz que representa al tablero
    -Row_y -> Coordenadas iniciales del jugador en las filas de la matriz que representa al tablero
    -Shape -> Representa la forma con la que se mostrara al jugador en pantalla 
*/
Player::Player(int column_x,int row_y, char shape)
: column_x(column_x),row_y(row_y),shape(shape){};

/*
Getters:
    - getX() -> conseguimos las coordenadas actuales del jugador en las columnas
    - getY() -> Conseguimos las coordenadas actuales del jugador en las filas
*/
const int& Player::getX() const{
    return column_x;
}

const int& Player::getY() const{
    return row_y;
}

/*
Setters:
    -setX(int columna_x) -> Nos permite cambiar las coordenadas del jugador en columnas (Util para el movimiento)
    -setY(int row_y) -> Nos permite cambiar las coordenadas del jugador en filas (Util para el movimiento del jugador)
*/
void Player::setX(int column_x){
    this->column_x = column_x;
}

void Player::setY(int row_y){
    this->row_y = row_y;
}

/*
ShowPlayer:
    -Nos permite dibujar al jugador en una coordenada especifica las cuales se guardan en los atributos de la clase
*/
void Player::ShowPlayer(){
    mvprintw(row_y,column_x,"%c",shape);
}

Player::~Player(){}