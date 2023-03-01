//
// Created by ofgha on 22/02/23.
//

#include "Undead.h"

std::string Undead::say_hi() const {
    if (getLifeState() == ELifeState::Immortal)
        return to_string() + " :\n\t... ! ... gak?";
    return to_string() + " is dead (truly dead) and thus can not answer...";
}

std::string Undead::to_string() const {
    return "["+ getRaceRepr(_race)+ "] " + _name ;
}

void Undead::growOlder() {
}

void Undead::onKilled() {
    std::cout << to_string() + " has been put to eternal rest..." << std::endl;
}

int Undead::initNewRelation(Npc &npc) const {
    return 0;
}

int Undead::talkWith(Npc &npc) const {
    return 0;
}
