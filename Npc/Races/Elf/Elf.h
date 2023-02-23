//
// Created by ofgha on 22/02/23.
//

#ifndef TEST1_ELF_H
#define TEST1_ELF_H

#include "../../Npc.h"

static const int ELF_LIFESPAN = 600;

class Elf : public Npc {
public:
    Elf(std::string name, EGender gender, int age) : Npc{} {
        _lifeState = ELifeState::ALIVE;
        _race = ERace::HUMAN;
        _name = name;
        _gender = gender;
        _age = age;
        _life_span = ELF_LIFESPAN * (.8 + (rand() % 40) / 100.0);
    }

    Elf(std::string name, EGender gender) : Elf{name, gender, 0} {
    }

    std::string say_hi() const override;

    std::string to_string() const override;

    int age() override;

    void kill() override;
};


#endif //TEST1_ELF_H
