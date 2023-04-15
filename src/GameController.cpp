//
// Created by Antonin on 13/04/2023.
//

#include "GameController.h"
#include "utils/Displayer.h"
#include "Npc/Races/Human/Human.h"
#include "Npc/Creator/NpcCreator.h"

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
    return GameController(date, village);
}
