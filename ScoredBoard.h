#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class PlayerRecord{
public:
    string name;
    int time;
    string FechaActual;
    bool operator<(PlayerRecord& other) {
        return this->time < other.time;
    }

    // colocar friend nos permite cambiar la sintaxis del operador 
    // Antes : PlayerRecord << file
    // Ahora : file << PlayerRecrod

    // Imprimir datos 
    friend ostream& operator<<(ostream& os, PlayerRecord& OtherPlayer);

    // Recibir datos
    friend istream& operator>>(istream& is, PlayerRecord& OtherPlayer);
};

class Scoreboard{
private:
    vector<PlayerRecord> records;

public:
    Scoreboard();

    void addRecord(string name,int time,string FechaActual);
    void displayScores();
};

#endif