//
// Created by ofgha on 21/02/23.
//

#include "Human.h"


std::string Human::say_hi() const {
    if (getLifeState() == ELifeState::Alive)
        return to_string() + " :\n\tHello ! I'm " + _name + "!";
    return to_string() + " is dead and thus can not answer...";
}

std::string Human::to_string() const {
    return "[" + NpcRace::to_string(_race) + " " + NpcGender::to_string(_gender) + " ] " + _name ;
}

void Human::growOlder() {
    if (!isAlive()) return;

    _age++;
    if (_age >= _life_span) {
        killHandler();
    }
}

void Human::onKilled() {
    std::cout << to_string() + " passed away at the growOlder of " + std::to_string(_age) << std::endl;
}

int Human::initNewRelation(Npc &npc) const {
    return 1;
}

int Human::talkWith(Npc &npc) const {
    return 50;
}

bool Human::canBreadWith(Npc &other) const {
    return false;
}


