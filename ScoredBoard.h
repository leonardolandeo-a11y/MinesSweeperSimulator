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