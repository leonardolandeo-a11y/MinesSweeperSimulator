#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"
#include <ncurses.h>
#include <random>

using namespace std;
/*
Variables globales indican el tamaño del tablero 
*/
const int m = 20;
const int n = 20;

/*
Clase Board:

* Atributos:
    - Tamaño del tablero (una matriz m x n)
    - Tenemos una matriz de Celdas (Cell) del mismo tamaño que el tablero representa una relacion de composicion entre el tablero y la clase Cell

* Metodos:
    - Constructor:
        - Solicitamos el tamaño del tablero 
    
    - CalculateNeighborBombs:
        [H][H][H]
        [H][P][H]
        [H][H][H]
        P: Jugador
        H: Lugar sin revelar ( 8 alrededor del jugador )
        - El metodo cuenta cuantas bombas hay a su alredor y coloca el numero en los atributos de la celda donde esta parado(Sera invisible a menos de que el jugador revele la celda donde esta parado)

    - ShowBoard:
        - Este metodo se encarga de dibujar el tablero completo junto con las banderas que hemos colocado y las celdas aun no reveladas 
        - Jerarquia de presentacion:
            - Banderas
            - Lugares sin revelar
            - Bombas
            - Numero de vecinos alrededor

            // Explicacion: La bandera tiene la mayor prioridad ya que impide que una celda pueda ser revelada hasta que el jugador la retire. Si la celda no tiene una bandera y aún no ha sido revelada se muestra # (que representa una casilla sin revelar). En caso de que la celda ya haya sido revelada, el programa verifica si contiene una bomba por eso la bomba tiene la tercera prioridad. Si la celda no contiene una bomba, entonces se muestra el número de bombas que hay en las ocho celdas adyacentes.
    - CreateFlag:
        - Este metodo se encarga de verificar que la celda donde se quiere colocar una bandera no haya sido revelada previamente. Si la celda no ha sido revelada dejara colocar una bandera.
    
    -PlaceBombs:
        - Espera como parametro un numero de bombas que se puede cambiar dependiendo la dificultad del juego
        - Mientras que hayan bombas restantes sin colocar en el tablero:
            - Obtendremos 2 coordenadas de manera aleatoria
            - Si aun no hemos colocado una bomba en ese lugar:
                - Agregaremos una bomba y sumaremos 1 a nuestro contador de bombas para tener el numero exacto solicitado de bombas en el parametro

    - RevealEmptyCells:
        - Metodo recursivo 
        - Caracteristicas:
            - No revela 2 veces
            - No revela si hay una bandera encima
            - No revela si existe una bomba en una celda
            - No revela nada alrededor de una celda que tenga mas de 1 bomba
        - Ejemplo:
            - Si el jugador revelo la casilla superior izquierda y retorna un 0 (Significa que no hay bombas a su alrededor)
            [0][H][H]
            [H][H][H]
            [H][H][H]
            
            - Automaticamente el programa revelara las celdas alrededor del primer 0 
            [0][0][H]
            [0][0][H]
            [H][H][H]

            - Aparecieron otros 0, lo que significa que alrededor de esos otros 0 no hay bombas por lo que el programa revelara esas posiciones
            [0][0][0]
            [0][0][0]
            [0][0][0]
            - Continuara asi hasta encontrar una celda la cual tenga 1 o mas bombas a su alrededor en ese caso parara.
    
    - RevealCell:
        - Revelara una celda en una coordenada especifica
        - Retornara un valor booleano dependiendo si existe o no una bomba en esa celda revelada
        - Si existe una bomba:
            -retornara falso lo que significa que piso una mina automaticamente termina el juego
        - llaamara al metodo RevealEmptyCells el cual recursivamente buscara las celdas con 0 bombas a su alrededor
        
*/


class Board{
private:
    int m;
    int n;
    vector<vector<Cell>> BoardMatrix;

public:
    Board(int m, int n);
    bool getRevealedCell(int x,int y);
    bool getFlaggedCell(int x, int y);
    int getNeighborBombsCell(int x, int y);
    bool CheckWin();

    void CalculateNeighborBombs();
    void ShowBoard();
    void RevealEmptyCells(int i, int j);
    void CreateFlag(int i, int j);


    void PlaceBombs(int numberBombs);

    
    bool RevealCell(int i, int j);
    
    ~Board(){}


};



#endif