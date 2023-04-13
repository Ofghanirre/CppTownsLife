//
// Created by Antonin on 13/04/2023.
//

#ifndef TEST1_GAMECONTROLLER_H
#define TEST1_GAMECONTROLLER_H

#include <string>
#include "utils/RpgDate.h"
#include "Village/Village.h"

#define VILLAGER_START_AMOUNT 1

using namespace std;

class GameController {
public:

    static GameController initNew();
private:
    GameController(RpgDate date, Village& village) :
        _rpgDate(date),
        _village{village}, _logger("Game Controller") {};

    RpgDate _rpgDate;
    Village _village;
    const Logger _logger;
};


#endif //TEST1_GAMECONTROLLER_H
