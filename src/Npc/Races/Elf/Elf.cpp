//
// Created by ofgha on 22/02/23.
//

#include "Elf.h"

std::string Elf::say_hi() const {
    if (getLifeState() == ELifeState::Alive)
        return to_string() + " :\n\tMae govannen ! I'm " + _name + "!";
    return to_string() + " is dead and thus can not answer...";
}

std::string Elf::to_string() const {
    return "["+ getRaceRepr(_race) +" "+ getGenderRepr(_gender) + " ] " + _name ;
}

void Elf::growOlder() {
    if (!isAlive()) return;

    _age++;
    if (_age >= _life_span) {
        killHandler();
    }
}

void Elf::onKilled() {
    std::cout << to_string() + " joined the stars at the growOlder of " + std::to_string(_age) << std::endl;
}

int Elf::initNewRelation(Npc &npc) const {
    return 0;
}

int Elf::talkWith(Npc &npc) const {
    return 1;
}

bool Elf::canBreadWith(Npc &other) const {
    return false;
}
