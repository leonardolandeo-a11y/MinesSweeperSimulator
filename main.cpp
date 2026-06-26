#include <bits/stdc++.h>
#include <ncurses.h>
#include <random>
#include "Board.h"
#include "Player.h"
#include "Cell.h"
using namespace std;



int main() {
    /*
    Funciones princiaples de ncurses:
        initscr -> Inicializa la biblioteca
        noecho(); -> No muestra las teclas cuando se escribe
        cbreak(); -> lee las teclas inmediatamente sin esperar a presioanr enter
        keypad(stdscr,TRUE); -> habilita las teclas de las flechas
    */
    initscr();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    srand(time(0));
    
    /* 
    Instancias de las clases:
        BoardGame -> Representa un puntero a el Heap donde estara la clase Board que representa al tablero
        PlayerGame -> Representa un puntero al heap donde estara la clase Player que representa al jugador
        
    */
    Board* BoardGame = new Board(m,n);
    Player* PlayerGame = new Player(0,2, '@');

    /*
    Variables:
        level -> representa cuantas bombas habra en el tablero
    */
    int level = 150;

    /*
    Metodos inciales:
        PlaceBombs(level) -> Colocamos las bombas en el tablero
        CalculateNeighborBombs() -> por cada celda calculamos cuantas bobmas hay a su alrededor
    */
    BoardGame->PlaceBombs(level);
    BoardGame->CalculateNeighborBombs();
    
    /*
    Bucle principal del juego:
        - clear() -> borra todo el contenido de la consola (Funciona como los frames que se van acutalizando mediante como cambia el juego)

        - BoardGame->ShowBoard(); -> Dependiendo cuantas veces se ejecute el ciclo while se dibujara nuestro tablero en la consola

        - PlayerGame->ShowPlayer(); -> Dependiendo cuantas veces se ejecute el ciclo while se dibujara a nuestro personaje en el tablero (Permite movernos de manera fluida)

        - refresh(); -> Actualiza la pantalla mostrando todos los cambios 

        - if (!PlayerGame->Move(BoardGame)) -> Si piso una mina entonces el juego acabara automaticamente
    */
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
    endwin(); // Restaura la terminal a su estado normal
    delete BoardGame; 
    delete PlayerGame;
    return 0;
}