#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>
#include "Board.h"
using namespace std;
/*
Clase jugador
* Atributos:
    -Coordenadas en x, y
    - Forma del personaje ("&","@",etc)
* Metodos:
    - Constructor:
        -Solicita los parametros de la coordenada y la forma del jugador
    -Getters:
        -getX() -> Retorna las coordenadas con respecto a en que columna se encuentra el jugador
        -getY() -> Retorna las coordenadsa con respecto a en que fila se encuentra el jugador
    -Setters:
        -setX( int colmna_x) -> Cambia la coordenada de la columna donde se encuentra el jugador
        -setY(int row_Y) -> Cambia la coordenada de la fila donde se encuentra el jugador

    -ShowPlayer() -> Se encarga de dibujar al jugador en consola con respecto a las coordenadas establecidas

    -Move(Board* board) -> Se encarga de manejar movimientos, colocar banderas y desbloquear espacios en el tablero

*/
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