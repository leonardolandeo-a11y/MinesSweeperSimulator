#include "Player.h"
#include "ComputerPlayer.h"
#include "Board.h"
ComputerPlayer::ComputerPlayer(int x, int y, char shape): Player(x,y,shape){};

/* Safe Move:
    - Busca una jugada segura. 
    - Recorre todo el tablero y solo analiza las casillas que ya fueron reveladas. 
    - Si alrededor de una casilla revelada ya hay tantas banderas como minas vecinas, entonces las demás casillas ocultas alrededor consideran seguras y se revelan.
*/

bool ComputerPlayer::SafeMove(Board* Board){
    for (int i = 0; i<m; i++){
        for (int j = 0; j< n; j++){

            if (Board->getRevealedCell(i,j) == true ){
                int CountFlagAround = 0;
                if (i >= 1 && j >= 1){
                    if (Board->getFlaggedCell(i-1,j-1) == true){
                        CountFlagAround++;
                    }
                }

                if (i >= 1){
                    if (Board->getFlaggedCell(i-1,j) == true){
                        CountFlagAround++;
                    }
                }

                if (i >= 1 && j < n-1){
                    if (Board->getFlaggedCell(i-1,j+1) == true){
                        CountFlagAround++;
                    }
                }

                if (j >= 1){
                    if (Board->getFlaggedCell(i,j-1) == true){
                        CountFlagAround++;
                    }
                }

                if (j < n-1){
                    if (Board->getFlaggedCell(i,j+1) == true){
                        CountFlagAround++;
                    }
                }

                if (i < m-1 && j >= 1){
                    if (Board->getFlaggedCell(i+1,j-1) == true){
                        CountFlagAround++;
                    }
                }

                if (i < m-1){
                    if (Board->getFlaggedCell(i+1,j) == true){
                        CountFlagAround++;
                    }
                }

                if (i < m-1 && j < n-1){
                    if (Board->getFlaggedCell(i+1,j+1) == true){
                        CountFlagAround++;
                    }
                }
                if (CountFlagAround == Board->getNeighborBombsCell(i,j)){

                    if (i >= 1 && j >= 1){
                        if (Board->getRevealedCell(i-1,j-1) == false && Board->getFlaggedCell(i-1,j-1)== false){
                            setY(i-1);
                            setX(j-1);
                            return Board->RevealCell(i-1,j-1);
                        }
                    }

                    if (i >= 1){
                        if (Board->getRevealedCell(i-1,j) == false  && Board->getFlaggedCell(i-1,j)== false){
                            setY(i-1);
                            setX(j);
                            return Board->RevealCell(i-1,j);
                        }
                    }

                    if (i >= 1 && j < n-1){
                        if (Board->getRevealedCell(i-1,j+1) == false &&   Board->getFlaggedCell(i-1,j+1)== false){
                            setY(i-1);
                            setX(j+1);
                            return Board->RevealCell(i-1,j+1);
                        }
                    }

                    if (j >= 1){
                        if (Board->getRevealedCell(i,j-1) == false  && Board->getFlaggedCell(i,j-1)== false){
                            setY(i);
                            setX(j-1);
                            return Board->RevealCell(i,j-1);
                        }
                    }

                    if (j < n-1){
                        if (Board->getRevealedCell(i,j+1) == false  && Board->getFlaggedCell(i,j+1)== false){
                            setY(i);
                            setX(j+1);
                            return Board->RevealCell(i,j+1);
                        }
                    }

                    if (i < m-1 && j >= 1){
                        if (Board->getRevealedCell(i+1,j-1) == false  && Board->getFlaggedCell(i+1,j-1)== false ){
                            setY(i+1);
                            setX(j-1);
                            return Board->RevealCell(i+1,j-1);
                        }
                    }

                    if (i < m-1){
                        if (Board->getRevealedCell(i+1,j) == false  && Board->getFlaggedCell(i+1,j)== false){
                            setY(i+1);
                            setX(j);
                            return Board->RevealCell(i+1,j);
                        }
                    }

                    if (i < m-1 && j < n-1){
                        if (Board->getRevealedCell(i+1,j+1) == false  && Board->getFlaggedCell(i+1,j+1)== false){
                            setY(i+1);
                            setX(j+1);
                            return Board->RevealCell(i+1,j+1);
                        }
                    }
                }
                
                
            }


        }
    }
    return false;
}

/* RamdonMove:
    - Realiza un movimiento aleatorio.
    - Se usa cuando la computadora no puede deducir una jugada segura ni colocar bandera.
*/

bool ComputerPlayer::RandomMove(Board* board){
    while (true){
        int x = rand()%20;
        int y = rand()%20;

        if (board->getFlaggedCell(x,y) == false && board->getRevealedCell(x,y) == false){
            
            return board->RevealCell(x,y);
        }
    }
}

/* PlaceFlagComputer:
    - Intenta colocar una bandera de forma lógica.
    - Recorre las casillas reveladas y cuenta cuántas casillas ocultas hay alrededor.
    - Si el número de casillas ocultas coincide con número de minas vecinas, entonces esas casillas ocultas deben ser minas y se colocan banderas.
*/

bool ComputerPlayer::PlaceFlagComputer(Board* board){
    for (int i = 0; i<m;i++){
        for (int j = 0; j<n;j++){

            if (board->getRevealedCell(i,j) == true){        
                int CountUnReveledAround = 0; 

                if (i >= 1 && j >= 1){
                    if (board->getRevealedCell(i-1,j-1) == false){
                        CountUnReveledAround++;
                    }
                }

                if (i >= 1){
                    if (board->getRevealedCell(i-1,j) == false){
                        CountUnReveledAround++;
                    }
                }

                if (i >= 1 && j < n-1){
                    if (board->getRevealedCell(i-1,j+1) == false){
                        CountUnReveledAround++;
                    }
                }

                if (j >= 1){
                    if (board->getRevealedCell(i,j-1) == false){
                        CountUnReveledAround++;
                    }
                }

                if (j < n-1){
                    if (board->getRevealedCell(i,j+1) == false){
                        CountUnReveledAround++;
                    }
                }

                if (i < m-1 && j >= 1){
                    if (board->getRevealedCell(i+1,j-1) == false){
                        CountUnReveledAround++;
                    }
                }

                if (i < m-1){
                    if (board->getRevealedCell(i+1,j) == false){
                        CountUnReveledAround++;
                    }
                }

                if (i < m-1 && j < n-1){
                    if (board->getRevealedCell(i+1,j+1) == false){
                        CountUnReveledAround++;
                    }
                }

                if (CountUnReveledAround == board->getNeighborBombsCell(i,j)){
                    if (i >= 1 && j >= 1){
                        if (board->getRevealedCell(i-1,j-1) == false && board->getFlaggedCell(i-1,j-1) == false){
                            setY(i-1);
                            setX(j-1);
                            board->CreateFlag(i-1,j-1);
                            return true;
                        }
                    }

                    if (i >= 1){
                        if (board->getRevealedCell(i-1,j) == false && board->getFlaggedCell(i-1,j) == false){
                            setY(i-1);
                            setX(j);
                            board->CreateFlag(i-1,j);
                            return true;
                        }
                    }

                    if (i >= 1 && j < n-1){
                        if (board->getRevealedCell(i-1,j+1) == false && board->getFlaggedCell(i-1,j+1) == false){
                            setY(i-1);
                            setX(j+1);
                            board->CreateFlag(i-1,j+1);
                            return true;
                        }
                    }

                    if (j >= 1){
                        if (board->getRevealedCell(i,j-1) == false && board->getFlaggedCell(i,j-1) == false){
                            setY(i);
                            setX(j-1);
                            board->CreateFlag(i,j-1);
                            return true;
                        }
                    }

                    if (j < n-1){
                        if (board->getRevealedCell(i,j+1) == false && board->getFlaggedCell(i,j+1) == false){
                            setY(i);
                            setX(j+1);
                            board->CreateFlag(i,j+1);
                            return true;
                        }
                    }

                    if (i < m-1 && j >= 1){
                        if (board->getRevealedCell(i+1,j-1) == false && board->getFlaggedCell(i+1,j-1) == false){
                            setY(i+1);
                            setX(j-1);
                            board->CreateFlag(i+1,j-1);
                            return true;
                        }
                    }

                    if (i < m-1){
                        if (board->getRevealedCell(i+1,j) == false && board->getFlaggedCell(i+1,j) == false){
                            setY(i+1);
                            setX(j);
                            board->CreateFlag(i+1,j);
                            return true;
                        }
                    }

                    if (i < m-1 && j < n-1){
                        if (board->getRevealedCell(i+1,j+1) == false && board->getFlaggedCell(i+1,j+1) == false){
                            setY(i+1);
                            setX(j+1);
                            board->CreateFlag(i+1,j+1);
                            return true;
                        }
                    }

                }
                

            }
        }
    }
    return false;
}

/* Move:
    - Es el método principal del jugador automático.
    - Define el orden de prioridad de las acciones de la computadora.
*/

bool ComputerPlayer::Move(Board* board){
    napms(500);
    if (SafeMove(board)){
        return true;
    }
    if (PlaceFlagComputer(board)){
        return true;
    }
    return RandomMove(board);
    
};

ComputerPlayer::~ComputerPlayer(){};