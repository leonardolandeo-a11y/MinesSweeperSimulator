#include "Cell.h"


/*
Constructor:
    - Caracteristicas: 
        - Inicializamos cada atributo
        // Al principio una celda no es una bomba, no ha sido revelada, no tiene una bandera y no tiene bombas a su alrededor
*/

Cell::Cell()
:bomb(false), revealed(false),flagged(false),NeighborBombs(0){};

/*
Getters:
    getBomb()-> Retorna true si la celda es una bomba y false si no lo es
    getRevealed() -> Retorna true si la celda ha sido revelada en caso contrario false
    getFlagged() -> Retorna true si la celda tiene una bandera encima en caso contrario retorna false
    getNeighborBombs() -> retorna cuantas bombas existen alrededor de la celda
    
*/
bool Cell::getBomb(){
    return bomb;
}
bool Cell::getRevealed(){
    return revealed;
}
bool Cell::getFlagged(){
    return flagged;
}
int Cell::getNeighborBombs(){
    return NeighborBombs;
}
/*
Setters:
    setBombs(bool bomb) -> Cambia el estado de una celda a bomba
    setReveal() -> Cambia el estado de una celda a revelada
    setFlag() -> Cambia el estado de una celda a bandera 
    setNeighborBombs(int bombs) -> Cambia el numero de bombas alrededor de una celda
*/
void Cell::setBombs(bool bomb){
    this->bomb = bomb;
}
void Cell::setReveal(){
    revealed = true;
}
void Cell::setFlag(){
    flagged = !flagged;
}
void Cell::setNeighborBombs(int bombs){
    NeighborBombs = bombs;
}