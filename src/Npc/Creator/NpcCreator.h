//
// Created by Antonin on 15/04/2023.
//

#ifndef TEST1_NPCCREATOR_H
#define TEST1_NPCCREATOR_H


#include "../Npc.h"
#include "../../Logger/Logger.h"
#include "../Races/Human/Human.h"
#include "../Races/Elf/Elf.h"
#include "../Races/Spirit/Spirit.h"
#include "../Races/Undead/Undead.h"

#define MIN_SYLLABLES 1
#define MAX_SYLLABLES 3

using namespace std;

class NpcCreator {
public:
    static unique_ptr<Npc>initNewCustomNpc();
    static unique_ptr<Npc>initNewRandomNpc();
private:
    static Logger logger;

    static string initNewCustomName();

    static EGender initNewCustomGender();

    static int initNewCustomAge();

    static unique_ptr<Human> initNewHuman(std::string name, EGender gender, int age);
    static unique_ptr<Elf> initNewElf(std::string name, EGender gender, int age);
    static unique_ptr<Spirit> initNewSpirit(std::string name, EGender gender);
    static unique_ptr<Undead> initNewUndead(std::string name);
};


#endif //TEST1_NPCCREATOR_H
