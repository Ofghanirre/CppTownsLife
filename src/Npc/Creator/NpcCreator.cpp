//
// Created by Antonin on 15/04/2023.
//

#include "NpcCreator.h"
#include "../../utils/Displayer.h"
#include "../../utils/Utils.h"

Logger NpcCreator::logger{"NpcCreator"};


unique_ptr<Npc> NpcCreator::initNewCustomNpc() {
    vector<ERace> races = getAllRace();
    ERace choice = choose<ERace>(logger, "Select the Race of the Npc", races, getRaceRepr);
    switch (choice) {
        case ERace::Human:
            return initNewHuman(initNewCustomName(), initNewCustomGender(), initNewCustomAge());
        case ERace::Elf:
            return initNewElf(initNewCustomName(), initNewCustomGender(), initNewCustomAge());
        case ERace::Undead:
            return initNewUndead(initNewCustomName());
        case ERace::Spirit:
            return initNewSpirit(initNewCustomName(), initNewCustomGender());
        default: {
            // Can not happen from normal calls
            throw "ERROR, unresolved ERACE value... Should not happen";
        }
    }
}

string NpcCreator::initNewCustomName() {
    return prompt<string>(logger, "What would be the name of the Npc ?", displayer_identity, displayer_truth, true);
}

EGender NpcCreator::initNewCustomGender() {
    vector<EGender> genders = getAllGender();
    return choose<EGender>(logger, "What would be the gender of the Npc?", genders, getGenderRepr, true);
}

int NpcCreator::initNewCustomAge() {
    return prompt<int>(logger, "What would be the age of the Npc ?", [](string value){ return std::stoi(value);}, [](int value){ return 0 <= value; }, true);
}

unique_ptr<Human> NpcCreator::initNewHuman(std::string name, EGender gender, int age) {
    return make_unique<Human>(name, gender, age);
}

unique_ptr<Elf> NpcCreator::initNewElf(std::string name, EGender gender, int age) {
    return make_unique<Elf>(name, gender, age);
}

unique_ptr<Spirit> NpcCreator::initNewSpirit(std::string name, EGender gender) {
    return make_unique<Spirit>(name, gender);
}

unique_ptr<Undead> NpcCreator::initNewUndead(std::string name) {
    return make_unique<Undead>(name);
}


unique_ptr<Npc> NpcCreator::initNewRandomNpc() {
    static auto races = getAllRace();
    static auto genders = getAllGender();
    ERace race = races[random_between(0, 2)];
    std::string name = NpcNameGenerator::generateNewName(race, 1, 3);
    EGender gender = genders[random_between(0, genders.size())];
    switch (race) {
        case ERace::Human:
            return initNewHuman(name, gender, Human::HumanLifespan / 4);
        case ERace::Elf:
            return initNewElf(name, gender, Elf::ElfLifespan / 10);
        case ERace::Undead:
            return initNewUndead(name);
        case ERace::Spirit:
            return initNewSpirit(name, gender);
        default: {
            // Can not happen from normal calls
            throw "ERROR, unresolved ERACE value... Should not happen";
        }
    }
}
