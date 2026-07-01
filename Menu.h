#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

class Menu{
public:
    Menu();
    int DrawInterfaceOptions();
    char PlayerOptions();
    char DifficultyInterface();
    char Win();
    void GameOver();
};

#endif