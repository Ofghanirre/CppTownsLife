#include <iostream>
#include "Npc/Npc.h"
#include "GameController.h"
#include "utils/Utils.h"
using namespace std;


void testWithGameController() {
    GameController controller = GameController::initNew();
}

void testNameGenerator() {
    for (int i = 0; i < 10; i++) {
        cout << NpcNameGenerator::generateNewName(ERace::Human, 3, 5) << endl;
    }
}

#include <ncurses.h>
#include <string>
#include <vector>


void testCurses() {
    initscr();

    // Calcul de la position du centre de la fenêtre
    int x, y;
    getmaxyx(stdscr, y, x);
    x = x / 2;
    y = y / 2;

    // Boucle de chargement
    while (true) {
        // Affichage de la barre de progression
        mvprintw(y, x-4, "[===]");
        refresh();

        // Pause de 0.5 secondes
        napms(500);

        // Affichage de la barre de progression
        mvprintw(y, x-4, "[== ]");
        refresh();

        // Pause de 0.5 secondes
        napms(500);

        // Affichage de la barre de progression
        mvprintw(y, x-4, "[=  ]");
        refresh();

        // Pause de 0.5 secondes
        napms(500);

        // Affichage de la barre de progression
        mvprintw(y, x-4, "[ ==]");
        refresh();

        // Pause de 0.5 secondes
        napms(500);
    }

    // Nettoyage de ncurses
    endwin();
}

int main() {
    srand(time(0));
    testWithGameController();
    return 0;
}
