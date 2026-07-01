#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct PlayerRecord{
    string name;
    int time;
};

class Scoreboard{
private:
    vector<PlayerRecord> records;

public:
    Scoreboard();

    void addRecord(string name,int time);
    void displayScores();
};

#endif