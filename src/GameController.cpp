//
// Created by Antonin on 13/04/2023.
//

#include "GameController.h"
#include "utils/Displayer.h"
#include "Npc/Races/Human/Human.h"
#include "Npc/Creator/NpcCreator.h"
#include "PlayerActions/PlayerAction.h"


Village initVillage(RpgDate& date) {
    string villageName;
    Logger logger{"Game Initialisation"};
    logger.logln(LogLevel::Info, "Prolog")
            << "With the danger of the world of Aeshan, it is wise to join forces and survive together..." << endl
            << "It is the choice made by a bunch of individuals gathered around a fire spot." << endl
            << endl
            << "A new Village is about to be created, but what should we call it?" << endl
            << endl;
    villageName = prompt<string>(logger, "Name", displayer_identity, displayer_truth, true);
    return Village{villageName, date.get_year()};
}

void initVillagers(Village& village) {
    Logger logger{"Village Initialisation"};
    logger.logln(LogLevel::Info, "Prolog")
        << "The Village of " << village.getName() << " has just been created and "<< VILLAGER_START_AMOUNT << " individuals are now part of it!" << endl
        << "Would you like fate to decide what they would be?" << endl;
    bool randomNpc = askBoolean(logger, "Do you want random first NPCs?");
    for (int i = 0; i < VILLAGER_START_AMOUNT; i++) {
        village.addNpc(randomNpc ? NpcCreator::initNewRandomNpc() : NpcCreator::initNewCustomNpc());
    }
}


GameController GameController::initNew() {
    RpgDate date{1000, Spring};
    Village village = initVillage(date);
    initVillagers(village);
    std::cout << "\n\n" << village << std::endl;
    return {date, village};
}

bool GameController::playerActionLoop() {
    static vector<EPlayerActions> actions = PlayerActions::getAll();
    EPlayerActions action;
    while (0 < (action = choose<EPlayerActions>(_logger,
                                                 "What actions would you like to do",
                                                 actions,
                                                 PlayerActions::to_string)))
    {
        PlayerAction f = _actions_map.at(action);
        f.playAction(*this);
        cout << "Action Point left : " << _action_token << endl;
    }
    return action == QUIT;
}

void GameController::start() {
    cout << "starting" << endl;
    bool isQuitting;
    while (true) {
        isQuitting = playerActionLoop();
        if (isQuitting) break;
        cout << _village.to_string() << endl;
        cout << "New Date : " << ++_rpgDate << endl;
    }

    cout << "exiting" << endl;
}



GameController::GameController(RpgDate date, Village &village) :
        _rpgDate(date),
        _village{village},
        _logger("Game Controller"),
        _action_token(10)
{
}

const Village &GameController::get_village() const {
    return _village;
}

Village &GameController::get_village() {
    return _village;
}

RpgDate &GameController::get_date() { return _rpgDate; }

const RpgDate &GameController::get_date() const {
    return _rpgDate;
}

std::map<EPlayerActions, PlayerAction> GameController::_actions_map = GameController::init_action_map();

map<EPlayerActions, PlayerAction> GameController::init_action_map() {
    auto f = [](GameController& c){ return true; };
    return {
            {QUIT, {0, f}},
            {FINISH, {0, f}},
            {UNKNOWN, {0, f}},
            {HELLO, {1, [](GameController& c){cout << c.get_date() << endl; return true;}}}
    };
}

const int& GameController::getActionToken() const {
    return _action_token;
}

int& GameController::getActionToken() {
    return _action_token;
}

