//
// Created by ofgha on 22/02/23.
//

#ifndef TEST1_UNDEAD_H
#define TEST1_UNDEAD_H


#include "../../Npc.h"

class Undead : public Npc {
public:
    Undead(std::string name) {
        _lifeState = ELifeState::Immortal;
        _race = ERace::Undead;
        _name = name;
        _gender = EGender::Unknown;
        _age = -1;
        _life_span = 0;
        _isBreedable = false;
    }

    std::string say_hi() const override;

    std::string to_string() const override;

    void growOlder() override;

    void onKilled() override;

    int initNewRelation(Npc &npc) const override;

    int talkWith(Npc& npc) const override;
};


#endif //TEST1_UNDEAD_H
