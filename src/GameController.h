//
// Created by Antonin on 13/04/2023.
//

#ifndef TEST1_GAMECONTROLLER_H
#define TEST1_GAMECONTROLLER_H

#include <string>
#include <functional>
#include "utils/RpgDate.h"
#include "Village/Village.h"
#include "PlayerActions/EPlayerActions.h"
#include "PlayerActions/PlayerAction.h"


#define VILLAGER_START_AMOUNT 5

class PlayerAction; // forward declaration

using namespace std;

class GameController {
protected:
    GameController(RpgDate date, Village& village);

    bool playerActionLoop();

public:
    static GameController initNew();

    ~GameController() {

    }

    void start();
    const Village& get_village() const;
    Village& get_village();
    const RpgDate& get_date() const;
    RpgDate& get_date();

    const int& getActionToken() const;
    int& getActionToken();

private:;
    RpgDate _rpgDate;
    Village _village;
    Logger _logger;
    int _action_token;

    static map<EPlayerActions, PlayerAction> _actions_map;

    static map<EPlayerActions, PlayerAction> init_action_map();
};

#endif //TEST1_GAMECONTROLLER_H
