//
// Created by ofgha on 22/02/23.
//

#ifndef TEST1_SPIRIT_H
#define TEST1_SPIRIT_H


#include "../../Npc.h"

class Spirit : public Npc {
public:
    Spirit(std::string name, EGender gender) : Npc() {
        _race = ERace::Spirit;
        _name = name;
        _gender = gender;
        _lifeState = ELifeState::Immortal;
        _isBreedable = false;
    }

    std::string to_string() const override;

    std::string say_hi() const override;

    void growOlder() override;

    void onKilled() override;

    int initNewRelation(Npc &npc) const override;

    int talkWith(Npc& npc) const override;
};


#endif //TEST1_SPIRIT_H
