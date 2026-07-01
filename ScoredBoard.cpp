#include "ScoredBoard.h"
#include <ncurses.h>

Scoreboard::Scoreboard(){

    ifstream file("scores.txt");

    PlayerRecord p;

    while(true){
        // Leer elementos
        file >> p.name; 
        file >> p.time;

        if(file.fail()){ // Si ya no quedan mas elementos en el Scores
            break;
        }

        records.push_back(p);
    }
    file.close();
}


void Scoreboard::addRecord(string name,int time){

    PlayerRecord p;

    p.name=name;
    p.time=time;

    records.push_back(p);

    // Escribimos datos en archivo
    ofstream file("scores.txt");

    for(int i=0;i<records.size() && i<10;i++){

        file<<records[i].name<<" "<<records[i].time<<endl;
    }

    file.close();
}

void Scoreboard::displayScores(){

    clear();

    mvprintw(2,10,"===============================");
    mvprintw(3,10,"      TOP 10 JUGADORES         ");
    mvprintw(4,10,"===============================");

    for(int i=0;i<records.size() && i<10;i++){

        mvprintw(6+i,10,"%d. %s - %d s",i+1, records[i].name.c_str() ,records[i].time);
    }

    mvprintw(18,10,"Presione una tecla...");
    refresh();
    getch();
}