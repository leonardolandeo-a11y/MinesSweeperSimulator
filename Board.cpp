#include "Board.h"
#include "ncurses.h"


/*
Constructor:
    m  y n -> tamaños de la matriz que representa al tablero
    BoardMatrix -> Matriz de celdas (Relacion de composicion)
*/


Board::Board(int m, int n):m(m),n(n), BoardMatrix(m,vector<Cell>(n)){};

/*
PlaceBombs:
    - Caracteristicas:
        - recibira como parametro un numero de bombas a colocar en el tablero
        - las bombas seran colocadas en posiciones aleatorias
        - No se colocan 2 bombas en un mismo lugar
    - Funcionamiento:
        1. Inicializamos un contador en 0 (Representa las bombas ya colocadas)
        2. Bucle mientras queden bombas por colocar
        3. Dentro obtenemos coordenadas aleatorias para colocar las bombas. Cuando coloquemos una bomba sumaremos 1 a nuestro contador
    - Codigo:
        - int bombs = 0; -> contador de bombas ya colocadas
        - while (bombs < numberBombs) -> Mientras existan bombas por colocar
        - int row = rand()%m; int col = rand()%n; -> Coordenadas aleatorias para colocar las bombas
        - if (!BoardMatrix[row][col].getBomb()) -> Si en esa celda aun no existe una bomba entonces
            BoardMatrix[row][col].setBombs(true); -> Agregamos una bomba
            bombs++; -> Sumamos 1 a nuestro contador de bombas colocadas
*/

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

/*
CalculateNeighborBombs:
    - Caracteristicas:
        - Contara cuantas bombas existen alrededor una celda y colocara este numero con un atributo que despues se mostrara cuando la celda sea revelada 
    - Funcionamiento:
        1. Recorrera cada una de las celdas 
        2. Por cada celda verificar si esta celda no es una bomba
        3. Si la celda no es una bomba contar revisar si las celdas a su alredeor son bombas. (Si son bombas sumar 1 a un contador que luego se colocara como atributo de la celda)
    -Codigo:
        - for(int i = 0; i< m; i++){ for (int j = 0; j< n;j++) -> Recorrer cada una de las celdas
        - if (BoardMatrix[i][j].getBomb() == false) -> si la celda no es una bomba entonces:
            int count = 0; -> Incializamos un contador
            // Alrededor de una celda pueden haber hasta 8 celdas que que el programa revisara. (si la celda alrededor es una bomba sumara 1 al contador)
            BoardMatrix[i][j].setAdjacentBombs(count); -> Enviaremos el contador como atributo de la celda donde nos ubicamos
*/
void Board::CalculateNeighborBombs(){
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
                BoardMatrix[i][j].setNeighborBombs(count);
                }
                

            }
            

        }
    }

/*
ShowBoard:
    - Caracteristicas:
        - Mostrara cada elemento en el tablero 
        - La forma dependera de la clase Cell (puede ser una bomba, una bandera, numero de bombas alrededor o una casilla sin revelar)
    - Funcionamiento:
        1. Recorrera cada elemento dentro del tablero
        2. Por cada elemento verificara si es una bandera una casilla por revelera, una bomba o un numero de bombas alredeor de una casilla
    - Codigo:
        - for (int i = 0; i< m; i++){for(int j= 0; j<n;j++){ -> Recorre cada casilla
        - if(BoardMatrix[i][j].getFlagged()) -> si es una bandera imprimira una F en la coordenada donde esta nuestro jugador
        - else if (!BoardMatrix[i][j].getRevealed() -> Si es una celda sin revelar entonces imprimira # 
        - else if (BoardMatrix[i][j].getBomb()) -> Si es una bomba imprimira una X 
        - Por otro lado imprimira un numero que representara el numero de bombas alrededor si no es una bomba y no hay una bandera 
*/
void Board::ShowBoard(){

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            
            if(BoardMatrix[i][j].getFlagged()){
                attron(COLOR_PAIR(2)); // Activa Amarillo
                mvprintw(i, j, "%c", 'F');
                attroff(COLOR_PAIR(2)); // Desactiva
            }
            else if (!BoardMatrix[i][j].getRevealed()){
                attron(COLOR_PAIR(1)); // Activa Verde
                mvprintw(i, j, "%c", '#');
                attroff(COLOR_PAIR(1)); // Desactiva
            }
            else if (BoardMatrix[i][j].getBomb()){
                attron(COLOR_PAIR(3)); // Activa Rojo
                mvprintw(i, j, "%c", 'X');
                attroff(COLOR_PAIR(3)); // Desactiva
            }
            else{
                int neighbors = BoardMatrix[i][j].getNeighborBombs();
                
                if (neighbors > 0) {
                    // Iniciamos en el selector de colores
                    int color_pair_id = neighbors + 3;  
                    
                    attron(COLOR_PAIR(color_pair_id));
                    mvprintw(i, j, "%d", neighbors);
                    attroff(COLOR_PAIR(color_pair_id));
                } else {
                    // Si son 0 entonces los dejaremos de gris 
                    mvprintw(i, j, "%c", '0'); 
                }
            }

        }
    }
    refresh();
}
/*
RevealEmptyCells:
    - Caracteristicas;
        - Buscara todas las celdas en las que haya 0 bombas a su alrededor hasta que encuentre celdas con mas de 1 bomba a su alrededor
    - Funcionamiento: 
        1. Verificara que las coordenadas no salgan del tablero
        2. Verificara que las casilla alrededor no haya sido reveladas aun.
        3. Verificara que las casillas alrededor no sean bombas.
        4. Revelara las casillas 
        5. Si una de las casillas tiene bombas a su alrededor entonces parara la recursividad en ese instante
        6. Ejecutara el mismo algoritmo para todas las casillas alrededor de la principal (Alrededor pueden haber hasta 8 casillas)
    -Codigo:
        - if (i < 0 || i >= m || j < 0 || j >= n) -> verificar que no salga de los limites del tablero
        - if (BoardMatrix[i][j].getRevealed()== true) -> Si la casilla ya fue revelada parara
        - if (BoardMatrix[i][j].getFlagged() == true) -> Si la casilla tiene una bandera parara
        - if (BoardMatrix[i][j].getBomb() == true) -> Si la casilla tiene una bomba parara 
        - BoardMatrix[i][j].setReveal(); -> Revelara la casilla 
        - if (BoardMatrix[i][j].getAdjacentBombs()>0) -> si la casilla tiene bombas a su alrededor parara
        - RevealEmptyCells(i,j) -> Ejecuta el algoritmo recursivamente a todas las casillasa su alrededor
*/

void Board::RevealEmptyCells(int i, int j){
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
    if (BoardMatrix[i][j].getNeighborBombs()>0){
        return;
    }
    RevealEmptyCells(i-1,j-1);
    RevealEmptyCells(i-1,j);
    RevealEmptyCells(i-1,j+1);
    RevealEmptyCells(i,j-1);
    RevealEmptyCells(i,j+1);
    RevealEmptyCells(i+1,j-1);
    RevealEmptyCells(i+1,j);
    RevealEmptyCells(i+1,j+1);


}

/*
CreateFlag:
    - Si la casilla aun no ha sido revelada permitira que el jugador pueda colocar una bandera
*/
void Board::CreateFlag(int i, int j){
    if (!BoardMatrix[i][j].getRevealed()){
        BoardMatrix[i][j].setFlag();
    }
    
}

/*
RevealCell:
    - Caracteristicas:
        - Permite verificar si el jugador ha pisado una bomba
        - Revelara recursivamente aplicando el algoritmo de RevealEmptyCells 
        - En caso haya pisado una bomba retornara false 
*/
bool Board::RevealCell(int i, int j){
    if (BoardMatrix[i][j].getFlagged()){
        return true;   
    }

    if (BoardMatrix[i][j].getBomb()){
        return false;   
    }

    RevealEmptyCells(i,j);
    return true;
}



/* Getters:
    - Usaremos los getters para darle informacion del tablero al computador 
    - Cada uno de estos revelara informacion acerca de la celda donde se esta intentando buscar algo

    - bool Board::getRevealedCell(int x, int y) -> Permite saber a la computadora si la celda ha sido revelada
    - bool Board::getFlaggedCell(int x, int y) -> Permite saber a la computadora si la celda tiene una bandera 
    - int Board::getNeighborBombsCell(int x, int y) -> Permite saber cuantas bombas hay al rededor de una casilla
*/
bool Board::getRevealedCell(int x, int y){
    return BoardMatrix[x][y].getRevealed();
}


bool Board::getFlaggedCell(int x, int y){
    return BoardMatrix[x][y].getFlagged();
}
int Board::getNeighborBombsCell(int x, int y){
    return BoardMatrix[x][y].getNeighborBombs();
}

/*
bool Board::CheckWin():
    - Recorreremos casilla por casilla para verificar que todas las casilals seguras (sin bombas) hayan sido reveladas
    - Retorna true si todas las casillas han sido reveladas
    - Retorna false si todavia hay celdas sin revelar
*/

bool Board::CheckWin(){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!BoardMatrix[i][j].getBomb() && !BoardMatrix[i][j].getRevealed()){
                return false; // aun falta revelar una celda segura
            }
        }
    }
    return true; 
}