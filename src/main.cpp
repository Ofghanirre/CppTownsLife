#include <iostream>
#include <memory>
#include "Npc/Npc.h"
#include "Npc/Races/Human/Human.h"
#include "Npc/Races/Elf/Elf.h"
#include "Npc/Races/Undead/Undead.h"
#include "Npc/Races/Spirit/Spirit.h"
#include "Village/Village.h"
#include "GameController.h"
#include "utils/Utils.h"

using namespace std;

bool atLeastOneAlive(std::vector<std::unique_ptr<Npc>>& npcVector) {
    for (const auto &npc: npcVector) {
        if (npc->isAlive()) {
            return true;
        }
    }
    return false;
}


void testWithoutVillage() {
    std::vector<std::unique_ptr<Npc>> npcs;
    npcs.emplace_back(std::make_unique<Human>("Marc", EGender::Male, 20));
    npcs.emplace_back(std::make_unique<Human>("Erika", EGender::Female));
    npcs.emplace_back(std::make_unique<Human>("Alix", EGender::Unknown));
    npcs.emplace_back(std::make_unique<Elf>("Imeniel", EGender::Female, 600));
    npcs.emplace_back(std::make_unique<Undead>("Bob"));
    npcs.emplace_back(std::make_unique<Spirit>("Alid'ia", EGender::Male));


    std::cout << "New Colony has started with " << npcs.size() << " inhabitants!" << std::endl;
    int age = 1;
    int blueMoonFrequency = 42;
    int goldMoonFrequency = 100;
    for (const auto &npc: npcs) {
        std::cout << npc->say_hi() << std::endl;
    }
    while (atLeastOneAlive(npcs)) {
        if (age % blueMoonFrequency == 0) {
            std::cout << "A blue moon has rizen on the year " + std::to_string(age) + ", citizen are happy but undead decay." << std::endl;
            for (const auto &item: npcs) {
                if (item->getRace() == ERace::Undead && item->isAlive()) {
                    item->killHandler();
                }
                std::cout << item->say_hi() << std::endl;
            }
        }

        if (age == goldMoonFrequency) {
            std::cout << "A gold moon has rizen on the year " + std::to_string(age) + ", spirits will slowly fade." << std::endl;
            for (const auto &item: npcs) {
                if (item->getRace() == ERace::Spirit) {
                    item->killHandler();
                }
            }
        }
//        std::cout << "New Year : " + std::to_string(age) << std::endl;
        for (const auto &item: npcs) {
            item->growOlder();
        }
        ++age;
    }
    std::cout << "The Colony is back to eternal silence...\n> Lasted " + std::to_string(age) + " years!" << std::endl;
};

void testWithVillage() {
    int year = 1000;

    Village village{"Lyrije", year};
    village.addNpc(std::make_unique<Human>("Inadriel", EGender::Male, 20));
    village.addNpc(std::make_unique<Human>("Lidia", EGender::Female, 19));
    village.addNpc(std::make_unique<Elf>("Lerinor", EGender::Female, 450));
    village.addNpc(std::make_unique<Spirit>("Har'Kal", EGender::Male));
    village.addNpc(std::make_unique<Undead>("Mal keshar"));

    std::cout << village << std::endl;
    while (village.getAliveInhabitantsAmount() > 0) {
        village.nextYearHandler();
        std::cout << "New Year " << year << std::endl;
        year++;
    }
    std::cout << village << std::endl;

    std::cout << "The only being remaining within the " << village.getName() << " Village are immortals.\nThe latters abandon the village" << std::endl;
    village.killAllInhabitants();
}

void testWithVillageAndInteraction() {
    int year = 1000;
    string villageName;
    Logger logger{"Game"};

    logger.logln(LogLevel::Info, "Prolog")
    << "With the danger of the world of Aeshan, it is wise to join forces and survive together...\n"
    << "It is the choice made by a bunch of individuals gathered around a fire spot.\n"
    << "\n"
    << "A new Village is about to be created, but what should we call it?\n"
    << "\n"
    << "[Name] > ";
    cin >> villageName;
    cout << endl;
    Village village{villageName, year};
    village.addNpc(make_unique<Human>("Inadriel", EGender::Male, 20));
    village.addNpc(make_unique<Human>("Lidia", EGender::Female, 19));
    village.addNpc(make_unique<Elf>("Lerinor", EGender::Female, 450));
    village.addNpc(make_unique<Spirit>("Har'Kal", EGender::Male));
    village.addNpc(make_unique<Undead>("Mal keshar"));

    while (village.getAliveInhabitantsAmount() > 0) {
        village.nextYearHandler();
        if (village.playAction() == VillageAction::Exit) break;
        logger.logln(LogLevel::Info, "New Year : " + std::to_string(++year));
    }
    std::cout << "\n\n" << village << std::endl;

    logger.logln(LogLevel::Info, "Informations");
    std::cout << "The only being remaining within the " << village.getName() << " Village are immortals.\nThe latters abandon the village" << std::endl;
    village.killAllInhabitants();
}

void testWithGameController() {
    GameController controller = GameController::initNew();
}

void testNameGenerator() {
    for (int i = 0; i < 100; i++) {
        cout << NpcNameGenerator::generateNewName(ERace::Human, 1, 5) << endl;
    }
}
int main() {
    srand(time(0));
    testWithGameController();
    return 0;
}
