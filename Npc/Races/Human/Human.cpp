//
// Created by ofgha on 21/02/23.
//

#include "Human.h"


std::string Human::say_hi() const {
    if (getLifeState() == ELifeState::ALIVE)
        return to_string() + " :\n\tHello ! I'm " + _name + "!";
    return to_string() + " is dead and thus can not answer...";
}

std::string Human::to_string() const {
    return "["+ getRaceRepr(_race) +" "+ getGenderRepr(_gender) + " ] " + _name ;
}

int Human::age() {
    if (!isAlive()) return _age;

    _age++;
    if (_age >= _life_span) {
        kill();
    }
    return _age;
}

void Human::kill() {
    _lifeState = ELifeState::DEAD;
    std::cout << to_string() + " passed away at the age of " + std::to_string(_age) << std::endl;
}


