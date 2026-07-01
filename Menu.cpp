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
            mvprintw(14, 10, "Registro (proximamente)");
            refresh();
            getch();
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
    mvprintw(4, 10, "   O                          ____________");
    mvprintw(5, 10, "  /|\\                        |            |");
    mvprintw(6, 10, "  / \\                        |   _____    |");
    mvprintw(7, 10, "                             |____________|");
    mvprintw(8, 10, "                                 |____|");
    mvprintw(9,10, "Opcion 1                          Opcion 2");
    mvprintw(12, 10, "Selecciona una opcion: ");
    
    mvprintw(15,10," ");
    refresh();
    char choice = getch();

    clear();
    return choice;
}


char Menu::Win(){

    mvprintw(2, 10, "===========================================================================");
    mvprintw(3, 10, "** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **");
    mvprintw(4, 10, "* *");
    mvprintw(5, 10, "* _______      ________   _   _                                       *");
    mvprintw(6, 10, "* \\\\      \\\\    /      /   | | | |                                      *");
    mvprintw(7, 10, "* \\\\      \\\\  /      /    | | | |     _   _                            *");
    mvprintw(8, 10, "* \\\\      \\\\/      /     | | | |    | | | |                           *");
    mvprintw(9, 10, "* \\\\            /      | |_| |    | |_| |                           *");
    mvprintw(10,10, "* \\\\    /\\\\    /       |  _  |    |  _  |                           *");
    mvprintw(11,10, "* \\\\  /  \\\\  /        | | | |    | | | |                           *");
    mvprintw(12,10, "* \\\\/    \\\\/         |_| |_|    |_| |_|                           *");
    mvprintw(13,10, "* *");
    mvprintw(14,10, "** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **");
    mvprintw(15,10, "===========================================================================");
    mvprintw(17, 10, "¿Volver a jugar?(1/0): ");
    
    mvprintw(15,10," ");
    refresh();
    char choice = getch();

    clear();
    return choice;

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