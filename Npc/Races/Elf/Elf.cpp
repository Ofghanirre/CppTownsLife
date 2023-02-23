//
// Created by ofgha on 22/02/23.
//

#include "Elf.h"

std::string Elf::say_hi() const {
    if (getLifeState() == ELifeState::ALIVE)
        return to_string() + " :\n\tMae govannen ! I'm " + _name + "!";
    return to_string() + " is dead and thus can not answer...";
}

std::string Elf::to_string() const {
    return "["+ getRaceRepr(_race) +" "+ getGenderRepr(_gender) + " ] " + _name ;
}

int Elf::age() {
    if (!isAlive()) return _age;

    _age++;
    if (_age >= _life_span) {
        kill();
    }
    return _age;
}

void Elf::kill() {
    _lifeState = ELifeState::DEAD;
    std::cout << to_string() + " joined the stars at the age of " + std::to_string(_age) << std::endl;
}
