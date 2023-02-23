#include <iostream>
#include <memory>
#include "Npc/Npc.h"
#include "Npc/Races/Human/Human.h"
#include "Npc/Races/Elf/Elf.h"
#include "Npc/Races/Undead/Undead.h"
#include "Npc/Races/Spirit/Spirit.h"
#include "Village/Village.h"

bool atLeastOneAlive(std::vector<std::unique_ptr<Npc>>& npcVector) {
    for (const auto &item: npcVector) {
        if ((*item).isAlive()) return true;
    }
    return false;
}


void testWithoutVillage() {
    std::vector<std::unique_ptr<Npc>> npcs;
    npcs.emplace_back(std::make_unique<Human>("Marc", EGender::MALE, 20));
    npcs.emplace_back(std::make_unique<Human>("Erika", EGender::FEMALE));
    npcs.emplace_back(std::make_unique<Human>("Alix", EGender::UNKNOWN));
    npcs.emplace_back(std::make_unique<Elf>("Imeniel", EGender::FEMALE, 600));
    npcs.emplace_back(std::make_unique<Undead>("Bob"));
    npcs.emplace_back(std::make_unique<Spirit>("Alid'ia", EGender::MALE));


    std::cout << "New Colony has started with " + std::to_string(npcs.size()) + " inhabitants!" << std::endl;
    int age = 1;
    for (const auto &item: npcs) {
        std::cout << item->say_hi() << std::endl;
    }
    while (atLeastOneAlive(npcs)) {
        if (age % 42 == 0) {
            std::cout << "A blue moon has rizen on the year " + std::to_string(age) + ", citizen are happy but undead decay." << std::endl;
            for (const auto &item: npcs) {
                if (item->getRace() == ERace::UNDEAD && item->isAlive()) {
                    item->kill();
                }
                std::cout << item->say_hi() << std::endl;
            }
        }

        if (age == 100) {
            std::cout << "A gold moon has rizen on the year " + std::to_string(age) + ", spirits will slowly fade." << std::endl;
            for (const auto &item: npcs) {
                if (item->getRace() == ERace::SPIRIT) {
                    item->kill();
                }
            }
        }
//        std::cout << "New Year : " + std::to_string(age) << std::endl;
        for (const auto &item: npcs) {
            item->age();
        }
        age++;
    }
    std::cout << "The Colony is back to eternal silence...\n> Lasted " + std::to_string(age) + " years!" << std::endl;
};

void testWithVillage() {
    int year = 1000;

    Village village{"Lyrije", year};
    village.addNpc(std::make_unique<Human>("Inadriel", EGender::MALE, 20));
    village.addNpc(std::make_unique<Human>("Lidia", EGender::FEMALE, 19));
    village.addNpc(std::make_unique<Elf>("Lerinor", EGender::FEMALE, 450));
    village.addNpc(std::make_unique<Spirit>("Har'Kal", EGender::MALE));
    village.addNpc(std::make_unique<Undead>("Mal keshar"));

    std::cout << village.to_string() << std::endl;
    while (village.getAliveInhabitants()) {
        village.age();
        std::cout << "New Year " << year << std::endl;
        year++;
    }
    std::cout << village.to_string() << std::endl;

    std::cout << "The only being remaining within the " << village.getName() << " Village are immortals.\nThe latters abandon the village" << std::endl;
    village.kill();
}
int main() {
    srand(time(0));
    testWithVillage();
    return 0;
}
