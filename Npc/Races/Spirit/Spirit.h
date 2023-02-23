//
// Created by ofgha on 22/02/23.
//

#ifndef TEST1_SPIRIT_H
#define TEST1_SPIRIT_H


#include "../../Npc.h"

class Spirit : public Npc {
public:
    Spirit(std::string name, EGender gender) : Npc() {
        _race = ERace::SPIRIT;
        _name = name;
        _gender = gender;
        _lifeState = ELifeState::IMMORTAL;
    }

    std::string to_string() const override;

    std::string say_hi() const override;

    int age() override;

    void kill() override;
};


#endif //TEST1_SPIRIT_H
