#include "HumanPlayer.h"
#include "Player.h"


/*

*/

HumanPlayer::HumanPlayer(int x,int y, char shape): Player(x,y,shape){}


/*
Move:
    Caracteristicas:
        - Retorna un valor de tipo bool porque el main está programado para terminar el juego cuando Move retorna false, ya que esto indica que el jugador ha pisado una mina.
        - Se ejecuta varias veces por segundo lo que otorga un movimiento fluido del jugador
        - Establece teclas con las que el jugador pude interactuar con el entorno (Revelar una casilla, colocar una bandera y moverse)
    Funcionamiento:
        1. Obtener coordenadas actuales:
            - Usamos los getters para obtener las coordenadas actuales y las guardamos en variables

        2. Obtener tecla presionada:
            - Con el comando getch() obtendremos la tecla presionada 

        3. Verificar que tecla presionamos:
            -Dependiendo de la tecla podremos realizar diferentes acciones
    Codigo:
        - int column_x =getX(); -> obtener coordenadas en columna
        -int row_y = getY(); -> obtener coordenadas en fila

        // En todos los casos evitamos salir del tablero con las condicionales
        - if (key == KEY_UP && row_y > 0) -> Desplazamiento hacia arriba del personaje
        - if (key == KEY_DOWN && row_y < m - 1) -> Desplazamiento hacia abajo del personaje
        - if (key == KEY_LEFT && column_x > 0) -> Desplazamiento hacia la derecha del personaje 
        - if (key == KEY_RIGHT && column_x < n - 1) -> Desplzamiento hacia la izquierda del personaje

        // Colocar una bandera
        - if (key == 'f') -> Con ayuda del comando CreateFlag de la clase board crearemos una bandera en la coordenada donde estamos.

        // Revelar una casilla
        - if (key == ' ') -> Con ayuda del metodo RevealCell de la clase Board liberaremos una casilla (Si la casilla que revelamos es una bomba automaticamente retornamos false)

        // Si al revelar no encontramos ni una bomba retornaremos true
*/



bool HumanPlayer::Move(Board* board) {

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

HumanPlayer::~HumanPlayer(){}