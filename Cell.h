#ifndef CELL_H
#define CELL_H

/*
Clase:
* Atributos:
    - ¿Es una bomba?
    - ¿Ha sido revelada?
    - ¿Tiene una bandera?
    - ¿Cuantas bombas hay a su alrededor?
* Metodos:
    - Constructor:
        - Todos sus atributos estan incializados por defecto 
    - Getters:
        - bool getBomb(); -> returna true si es una bomba en caso contrario false
        - bool getRevealed(); -> retorna true si ha sido revelada encaso contrario false
        - bool getFlagged(); -> retorna true si tiene una bandera en caso contrario false
        - int getNeighborBombs(); -> retorna cuantas bombas existen alrededor de una celda
        - void setBombs(bool bomb); -> cambia el estado de la celda cuando existe una bomba en esta misma
        - void setReveal(); -> cambia el estado de la celda cuando ha sido revelada
        - void setFlag(); -> Cambia el estado de la celda cuando se ha colocado una bandera encima
        - void setNeighborBombs(int bombs); -> cambia el estado del numero de bombas que hay alrededor de una celda
*/
class Cell{
private:
    bool bomb;
    bool revealed;
    bool flagged;
    int NeighborBombs;

public:
    Cell();
    
    bool getBomb();
    bool getRevealed();
    bool getFlagged();
    int getNeighborBombs();
    void setBombs(bool bomb);
    void setReveal();
    void setFlag();
    void setNeighborBombs(int bombs);



};




#endif