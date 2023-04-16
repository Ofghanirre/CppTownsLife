//
// Created by Antonin on 16/04/2023.
//

#ifndef TEST1_PLAYERACTION_H
#define TEST1_PLAYERACTION_H

#include <functional>
#include <utility>
#include "../GameController.h"

using namespace std;

class GameController; // forward declaration

class PlayerAction {
public:
    using ActionFunction = function<bool(GameController&)>;

    PlayerAction(int price, ActionFunction action);

    int getPrice() const;
    const ActionFunction &getAction() const;

    bool playAction(GameController& gameController);

private:
    int _price;
    ActionFunction _action;

    static bool canPayAction(GameController &gameController, PlayerAction& playerAction);
    static bool payAction(GameController& gameController, PlayerAction& playerAction);
};


#endif //TEST1_PLAYERACTION_H
