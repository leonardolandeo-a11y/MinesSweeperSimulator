#include "Menu.h"
#include <ncurses.h>

using namespace std;
Menu::Menu(){}

char Menu::DifficultyInterface(){
    clear();
    mvprintw(4, 10, "##############################################################");
    mvprintw(5, 10, "#                                                            #");
    mvprintw(6, 10, "#                >>> MENU DE DIFICULTAD <<<                  #");
    mvprintw(7, 10, "#                                                            #");
    mvprintw(8, 10, "#                    (1)    FACIL                            #");
    mvprintw(9, 10, "#                    (2)    MEDIO                            #");
    mvprintw(10,10, "#                    (3)   DIFICIL                           #");
    mvprintw(11,10, "#                                                            #");
    mvprintw(12,10, "##############################################################");


    mvprintw(14, 10, "Selecciona una opcion: ");
    mvprintw(15,10," ");
    refresh();
    char choice = getch();

    clear();
    return choice;
}
int Menu::DrawInterfaceOptions(){
    mvprintw(2, 10, "==============================================================");
    mvprintw(3, 10, " __  __ ___ _   _ _____ ____  _    _ _ _ _____ _____ ____  ");
    mvprintw(4, 10, "|  \\/  |_ _| \\ | | ____/ ___|| |  | | | | ____| ____|  _ \\ ");
    mvprintw(5, 10, "| |\\/| || ||  \\| |  _| \\___ \\| |  | | | |  _| |  _| | |_) |");
    mvprintw(6, 10, "| |  | || || |\\  | |___ ___) | |__| | |_| |___| |___|  __/ ");
    mvprintw(7, 10, "|_|  |_|___|_| \\_|_____|____/ \\____/ \\___/|_____|_____|_|   ");
    mvprintw(8, 10, "==============================================================");

    mvprintw(9, 10, "1. Jugar");
    mvprintw(10, 10, "2. Dificultad");
    mvprintw(11, 10, "3. Registro");
    mvprintw(12, 10, "0. Salir");

    mvprintw(14, 10, "Selecciona una opcion: ");
    refresh();
    mvprintw(15,10," ");
    char choice = getch();

    switch (choice) {
        case '1':
            clear();
            mvprintw(14, 10, "Iniciando juego...");
            refresh();
            napms(1000);
            clear();
            return 1;

        case '2':
            clear();
            return 2;
        
        case '3':
            clear();
            return 3;

        case '0':
            endwin();
            exit(0);
            clear();

        default:
            mvprintw(16, 10, "Opcion invalida");
            refresh();
            getch();
            clear();
            return 0;
    }
}
char Menu::PlayerOptions(){
    clear();
    mvprintw(3,  6, "#################################################################");
    mvprintw(4,  6, "#                     SELECCIONA UNA OPCION                     #");
    mvprintw(5,  6, "#################################################################");

    mvprintw(7, 10, "      O                           .----------------.");
    mvprintw(8, 10, "     /|\\                          |     PLAY       |");
    mvprintw(9, 10, "     / \\                          |     [>_]       |");
    mvprintw(10,10, "                                  '----------------'");
    mvprintw(11,10, "                                        ||");
    mvprintw(12,10, "                                      __||__");

    mvprintw(14,8, "        [1] Jugadora        [2] Computadora");

    mvprintw(16,6, "#################################################################");
    mvprintw(17,20, "Selecciona una opcion: ");
    mvprintw(18,6, "#################################################################");
    
    refresh();
    char choice = getch();

    clear();
    return choice;
}


void Menu::Win(){

    mvprintw(2,  8, "=====================================================================");
    mvprintw(3,  8, "||                                                               ||");
    mvprintw(4,  8, "|| __        ___ _   _                                           ||");
    mvprintw(5,  8, "|| \\ \\      / (_) | | |                                          ||");
    mvprintw(6,  8, "||  \\ \\ /\\ / /| | |_| |                                          ||");
    mvprintw(7,  8, "||   \\ V  V / | |  _  |                                          ||");
    mvprintw(8,  8, "||    \\_/\\_/  |_|_| |_|                                          ||");
    mvprintw(9,  8, "||                                                               ||");
    mvprintw(10, 8, "=====================================================================");

}

void Menu::GameOver(){
    mvprintw(6,  10, "  ____    _    __  __ _____    _____     _____ ____  ");
    mvprintw(7,  10, " / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ ");
    mvprintw(8,  10, "| |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |");
    mvprintw(9,  10, "| |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ < ");
    mvprintw(10, 10, " \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\");

    // Mensaje inferior para el usuario
    mvprintw(13, 14, "=================================================");
    mvprintw(14, 20, "Presiona cualquier tecla para salir...");
    mvprintw(15, 14, "=================================================");
}
void Menu::PlayAgain(){
    mvprintw(6,  8, " ____  _        _ __   __     _    ____    _    ___ _   _ ");
    mvprintw(7,  8, "|  _ \\| |      / \\\\ \\ / /    / \\  / ___|  / \\  |_ _| \\ | |");
    mvprintw(8,  8, "| |_) | |     / _ \\\\ V /    / _ \\\\ |  _  / _ \\  | ||  \\| |");
    mvprintw(9,  8, "|  __/| |___ / ___ \\| |    / ___ \\ |_| |/ ___ \\ | || |\\  |");
    mvprintw(10, 8, "|_|   |_____/_/   \\_\\_|   /_/   \\_\\____/_/   \\_\\___|_| \\_|");

    mvprintw(13, 14, "=================================================");
    mvprintw(14, 18, "Presiona 1 para jugar otra vez...");
    mvprintw(15, 14, "=================================================");
}