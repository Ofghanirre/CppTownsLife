//
// Created by Antonin on 16/04/2023.
//

#include "PlayerAction.h"

int PlayerAction::getPrice() const {
    return _price;
}


const PlayerAction::ActionFunction &PlayerAction::getAction() const {
    return _action;
}

bool PlayerAction::canPayAction(GameController &gameController, PlayerAction& playerAction) {
    int& actionToken = gameController.getActionToken();
    if (actionToken < playerAction._price) {
        return false;
    }
    return true;
}

bool PlayerAction::payAction(GameController &gameController, PlayerAction& playerAction) {
    int& actionToken = gameController.getActionToken();
    if (actionToken < playerAction._price) {
        return false;
    }
    actionToken -= playerAction._price;
    return true;
}

bool PlayerAction::playAction(GameController &gameController) {
    if (!canPayAction(gameController, *this)) return false;
    if (!_action(gameController)) return false;
    return payAction(gameController, *this);
}

PlayerAction::PlayerAction(int price, ActionFunction action): _price{price}, _action{action} {

}

