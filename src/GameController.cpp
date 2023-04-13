//
// Created by Antonin on 13/04/2023.
//

#include "GameController.h"
#include "utils/Displayer.h"
#include "Npc/Races/Human/Human.h"
#include <functional>

unique_ptr<Npc> initNewCustomNpc();
unique_ptr<Human> initNewCustomHuman();

auto _identity = [](const std::string& str) { return str; };
auto _truth = [](const auto v){return true;};
Village initVillage(RpgDate& date) {
    string villageName;
    Logger logger{"Game Initialisation"};
    logger.logln(LogLevel::Info, "Prolog")
            << "With the danger of the world of Aeshan, it is wise to join forces and survive together..." << endl
            << "It is the choice made by a bunch of individuals gathered around a fire spot." << endl
            << endl
            << "A new Village is about to be created, but what should we call it?" << endl
            << endl;
    villageName = prompt<string>(logger, "Name", _identity, _truth, true);
    return Village{villageName, date.get_year()};
}

void initVillagers(Village& village) {
    Logger logger{"Village Initialisation"};
    logger.logln(LogLevel::Info, "Prolog")
        << "The Village of " << village.getName() << " has just been created and "<< VILLAGER_START_AMOUNT << " individuals are now part of it!" << endl
        << "Would you like fate to decide what they would be?" << endl;

    if (!askBoolean(logger, "Do you want random first NPCs?")) {
        for (int i = 0; i < VILLAGER_START_AMOUNT; i++) {
            village.addNpc(initNewCustomNpc());
        }
    }
}

unique_ptr<Npc> initNewCustomNpc() {
    Logger logger{"Npc Creator"};
    vector<ERace> races = getAllRace();
    ERace choice = choose<ERace>(logger, "Select the Race of the Npc", races, getRaceRepr);
    switch (choice) {
        case ERace::Human:
            return initNewCustomHuman();
        case ERace::Elf:
            break;
        case ERace::Undead:
            break;
        case ERace::Spirit:
            break;
        default: {

        }
    }
    return std::unique_ptr<Npc>();
}

string initNewCustomName(Logger& logger) {
    return prompt<string>(logger, "What would be the name of the Npc ?", _identity, _truth, true);
}

EGender initNewCustomGender(Logger& logger) {
    vector<EGender> genders = getAllGender();
    return choose<EGender>(logger, "What would be the gender of the Npc?", genders, getGenderRepr, true);
}

int initNewCustomAge(Logger& logger) {
    return prompt<int>(logger, "What would be the age of the Npc ?", [](string value){ return std::stoi(value);}, [](int value){ return 0 <= value; }, true);
}

unique_ptr<Human> initNewCustomHuman() {
    Logger logger{"Human Creator"};

    return make_unique<Human>(initNewCustomName(logger), initNewCustomGender(logger), initNewCustomAge(logger));
}


GameController GameController::initNew() {
    RpgDate date{1000, Spring};
    Village village = initVillage(date);
    initVillagers(village);
    std::cout << "\n\n" << village << std::endl;
    return GameController(date, village);
}
