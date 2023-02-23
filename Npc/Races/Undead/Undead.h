//
// Created by ofgha on 22/02/23.
//

#ifndef TEST1_UNDEAD_H
#define TEST1_UNDEAD_H


#include "../../Npc.h"

class Undead : public Npc {
public:
    Undead(std::string name) : Npc{} {
        _lifeState = ELifeState::IMMORTAL;
        _race = ERace::UNDEAD;
        _name = name;
        _gender = EGender::UNKNOWN;
        _age = -1;
        _life_span = 0;
    }

    std::string say_hi() const override;

    std::string to_string() const override;

    int age() override;

    void kill() override;
};


#endif //TEST1_UNDEAD_H
