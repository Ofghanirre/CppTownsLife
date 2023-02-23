//
// Created by ofgha on 22/02/23.
//

#include "Undead.h"

std::string Undead::say_hi() const {
    if (getLifeState() == ELifeState::IMMORTAL)
        return to_string() + " :\n\t... ! ... gak?";
    return to_string() + " is dead (truly dead) and thus can not answer...";
}

std::string Undead::to_string() const {
    return "["+ getRaceRepr(_race)+ "] " + _name ;
}

int Undead::age() {
    return -1;
}

void Undead::kill() {
    _lifeState = ELifeState::DEAD;
    std::cout << to_string() + " has been put to eternal rest..." << std::endl;
}
