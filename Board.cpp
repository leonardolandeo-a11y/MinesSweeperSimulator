#include "Board.h"


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

    for (int i = 0; i< m; i++){
        for(int j= 0; j<n;j++){
            if(BoardMatrix[i][j].getFlagged()){
                mvprintw(i,j,"%c",'F');
            }
            else if (!BoardMatrix[i][j].getRevealed()){
                mvprintw(i,j,"%c",'#');
            }
            else if (BoardMatrix[i][j].getBomb()){
                mvprintw(i,j,"%c",'X');
            }
            else{
                mvprintw(i,j,"%d",BoardMatrix[i][j].getNeighborBombs());
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
