#include <bits/stdc++.h>
#include <ncurses.h>
#include <random>
#include "Board.h"
#include "Player.h"
#include "Cell.h"
#include "Menu.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include <ctime>
using namespace std;



int main() {
    
    /*
    Funciones princiaples de ncurses:
        initscr -> Inicializa la biblioteca
        noecho(); -> No muestra las teclas cuando se escribe
        cbreak(); -> lee las teclas inmediatamente sin esperar a presioanr enter
        keypad(stdscr,TRUE); -> habilita las teclas de las flechas
    */
    // CORRECCIÓN: Se eliminó la doble inicialización de initscr y start_color, dejando el orden correcto.
    initscr();
    start_color();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    srand(time(0));

    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // Para el '#' verde
    init_pair(2, COLOR_YELLOW, COLOR_BLACK); // Para la 'F' Amarillo
    init_pair(3, COLOR_RED, COLOR_BLACK);    // Para la 'X' roja
    // Colores para los números (Del 1 al 8)
    init_pair(4, COLOR_BLUE, COLOR_BLACK);    // 1: Azul
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);   // 2: Verde
    init_pair(6, COLOR_BLUE, COLOR_BLACK);     // 3: Rojo
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK); // 4: Morado
    init_pair(8, COLOR_CYAN, COLOR_BLACK);    // 5: Celeste
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);  // 6: Amarillo
    init_pair(10, COLOR_WHITE, COLOR_BLACK);  // 7: Blanco
    init_pair(11, COLOR_BLUE, COLOR_BLACK);   // 8: Azul 
    /* Instancias de las clases:
        BoardGame -> Representa un puntero a el Heap donde estara la clase Board que representa al tablero
        PlayerGame -> Representa un puntero al heap donde estara la clase Player que representa al jugador (Usamos como clase base a la clase Player dado que la clase HumanPlayer es un tipo de jugador)
        Menu -> Representa el menu del jugador donde eligira la dificultad de ljuego y el tipo de juego
    */
    // NOTA: Asegúrate de tener m y n definidos previamente en tus archivos de configuración, o cámbialos por valores fijos (ej: 10, 10) si da error.
    Board* BoardGame = new Board(m,n);
    Player* PlayerGame = new HumanPlayer(0,2, '@');
    Player* PlayerGameComputer = new ComputerPlayer(0,2,'@');

    Menu* menu = new Menu();
    /*
    Variables:
        level -> representa cuantas bombas habra en el tablero
    */
    int level = 30;

    /*
    Metodos inciales:
        PlaceBombs(level) -> Colocamos las bombas en el tablero
        CalculateNeighborBombs() -> por cada celda calculamos cuantas bobmas hay a su alrededor
    */
    BoardGame->PlaceBombs(level);
    BoardGame->CalculateNeighborBombs();
    
    /*
    Bucle principal del juego:
        - Opciones -> Representa las opciones generales del juego como empezar la partida o cambiar la dificultad

        - clear() -> borra todo el contenido de la consola (Funciona como los frames que se van acutalizando mediante como cambia el juego)
        
        - if (timer ==0)-> Permite Dibuajr la interfaz en la primera iteraccion del juego
        
        - BoardGame->ShowBoard(); -> Dependiendo cuantas veces se ejecute el ciclo while se dibujara nuestro tablero en la consola

        - PlayerGame->ShowPlayer(); -> Dependiendo cuantas veces se ejecute el ciclo while se dibujara a nuestro personaje en el tablero (Permite movernos de manera fluida)

        - refresh(); -> Actualiza la pantalla mostrando todos los cambios 

        - if (!PlayerGame->Move(BoardGame)) -> Si piso una mina entonces el juego acabara automaticamente
    */

    /*
        timer -> Nos permite detectar la primera iteracion luego de eso no se usa
        StartTime -> Viene de ctime nos permite tener una cuenta de cuando empezo el tiempo de juego
        */
    int timer = 0; 
    int Opciones = 0;       
    char ModoJuego = 0;    
    bool modoElegido = false;
    time_t StartTime = time(nullptr);

    while(true){
        clear();
        if (BoardGame->CheckWin()){
            clear();
            char PlayAgain = menu->Win();
            if (PlayAgain == '1'){
                delete BoardGame;
                BoardGame = new Board(m,n);
                BoardGame->PlaceBombs(level);
                BoardGame->CalculateNeighborBombs();
                Opciones = 0;
                modoElegido = false;
                ModoJuego = 0;
                timer = 0;
                StartTime = time(nullptr);
                continue;
            }
            if (PlayAgain == '0'){
                break;
            }
            

        }
        if (timer == 0){
            Opciones = menu->DrawInterfaceOptions();
            
        }
        
        if (Opciones == 1){
            clear();

            if (modoElegido == false){
                ModoJuego = menu->PlayerOptions();  
                modoElegido = true;
                StartTime = time(nullptr);
            }

            time_t CurrentTime = time(nullptr);
            int Time = CurrentTime - StartTime;
            mvprintw(22,0,"Time %d s",Time);
            if (level == 30){
                mvprintw(23,0, "Dificultad: Facil");
            }
            if (level == 70){
                mvprintw(23,0, "Dificultad: Media");
            }
            if (level == 100){
                mvprintw(23,0, "Dificultad: Dificil");
            }

            bool vivo = true;

            if (ModoJuego =='1'){
                BoardGame->ShowBoard();
                PlayerGame->ShowPlayer();
                refresh();
                vivo = PlayerGame->Move(BoardGame);
            }
            else if (ModoJuego == '2'){
                BoardGame->ShowBoard();
                PlayerGameComputer->ShowPlayer();
                refresh();
                vivo = PlayerGameComputer->Move(BoardGame);
            }

            if (!vivo){
                clear();
                menu->GameOver();
                refresh();
                getch();      
                break;
            }
        }

        if (Opciones == 2){
            char GameDifficulty = menu->DifficultyInterface();
            if (GameDifficulty == '1'){
                level = 30;
            }
            else if (GameDifficulty == '2'){
                level = 70;
            }
            else if (GameDifficulty == '3'){
                level = 100;
            }

            delete BoardGame;
            BoardGame = new Board(m,n);
            BoardGame->PlaceBombs(level);
            BoardGame->CalculateNeighborBombs();
            Opciones = 0;
            timer = 0;
            continue;
        }

        timer++;
    }
    endwin(); // Restaura la terminal a su estado normal
    delete BoardGame; 
    delete PlayerGame;
    delete PlayerGameComputer;
    delete menu;
    return 0;
}