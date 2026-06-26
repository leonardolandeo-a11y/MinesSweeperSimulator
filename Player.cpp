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
