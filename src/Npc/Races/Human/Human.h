//
// Created by ofgha on 21/02/23.
//

#ifndef TEST1_HUMAN_H
#define TEST1_HUMAN_H


#include <utility>
#include <unordered_map>

#include <random>

#include "../../Npc.h"


static const std::unordered_map<ERace, int> human_racialRelation{{ERace::Human, 0}, {ERace::Elf, -5}, {ERace::Spirit, 5}, {ERace::Undead, -10}};

class Human : public Npc {
private:
    static inline const int HumanLifespan = 60;

public:
    Human(std::string name, EGender gender, int age) : Npc{} {
        _lifeState = ELifeState::Alive;
        _race = ERace::Human;
        _name = name;
        _gender = gender;
        _age = age;
        _life_span = HumanLifespan * (.8 + (rand() % 40) / 100.0);
    }

    Human(std::string name, EGender gender) : Human{name, gender, 0} {
    }

    std::string say_hi() const override;

    std::string to_string() const override;

    void growOlder() override;

    void onKilled() override;

    int getRelation(Npc &npc) const override;
};


#endif //TEST1_HUMAN_H
