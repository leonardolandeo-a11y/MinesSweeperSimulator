#include "ScoredBoard.h"
#include <ncurses.h>
#include <algorithm>

// Imprimir el nombre, el tiempo y la fecha actual cada vez que usemos
// 
ostream& operator<<(ostream& os, PlayerRecord& OtherPlayer){
    os<<OtherPlayer.name<<" "<<OtherPlayer.time<< " "<<OtherPlayer.FechaActual;
    return os;
}
// Recibe datos y lo guarda 
istream& operator>>(istream& is, PlayerRecord& OtherPlayer){
    is >> OtherPlayer.name>>OtherPlayer.time>>OtherPlayer.FechaActual;
    return is;
}




Scoreboard::Scoreboard(){

    ifstream file("scores.txt");

    PlayerRecord p;

    while(true){
        // Sobrecarga file>>
        // Lee file y guarda todo en p (name, time y FechaActual)
        file >> p;


        if(file.fail()){ // Si ya no quedan mas elementos en el Scores
            break;
        }

        records.push_back(p);
    }
    file.close();
}


void Scoreboard::addRecord(string name,int time,string FechaActual){

    PlayerRecord p;

    p.name=name;
    p.time=time;
    p.FechaActual = FechaActual;

    records.push_back(p);

    // sort usa el operador <
    // Nosotros estamos sobrecargando el operador <
    // Sort compara los elementos dentro del vector como son de tipo PlayerRecord entonces los compara
    // PlayerRecord1 < PlayerRecord2 ??? 
    // Nosotros hemos sobrecargado el operador tal que cuando ocurra esa operacion compare exactamente los tiempso de cada PlayerRecord 
    // Sort compara con respecto al tiempo de cada jugador
    sort(records.begin(), records.end());
    // Escribimos datos en archivo
    ofstream file("scores.txt");
    

    for(int i=0;i<records.size() ;i++){

        // Sobrecarga file<<
        // lee file y imprime por filas 
        file<<records[i]<<endl;
    }

    file.close();
}

void Scoreboard::displayScores(){

    clear();

    mvprintw(2,10,"===============================");
    mvprintw(3,10,"           JUGADORES          ");
    mvprintw(4,10,"===============================");

    for(int i=0;i<records.size();i++){

        mvprintw(6+i,10,"%d. %s - %d s - %s",i+1, records[i].name.c_str() ,records[i].time, records[i].FechaActual.c_str());
    }

    mvprintw(18,10,"Presione una tecla...");
    refresh();
    getch();
}