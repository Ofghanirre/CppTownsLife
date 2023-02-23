//
// Created by ofgha on 21/02/23.
//

#ifndef TEST1_HUMAN_H
#define TEST1_HUMAN_H


#include <utility>
#include <random>

#include "../../Npc.h"

static const int HUMAN_LIFESPAN = 60;

class Human : public Npc {
public:
    Human(std::string name, EGender gender, int age) : Npc{} {
        _lifeState = ELifeState::ALIVE;
        _race = ERace::HUMAN;
        _name = name;
        _gender = gender;
        _age = age;
        _life_span = HUMAN_LIFESPAN * (.8 + (rand() % 40) / 100.0);
    }

    Human(std::string name, EGender gender) : Human{name, gender, 0} {
    }

    std::string say_hi() const override;

    std::string to_string() const override;

    int age() override;

    void kill() override;
};


#endif //TEST1_HUMAN_H
