//
// Created by ofgha on 22/02/23.
//

#ifndef TEST1_ELF_H
#define TEST1_ELF_H

#include "../../Npc.h"


class Elf : public Npc {
public:
    static inline const int ElfLifespan = 600;

    Elf(std::string name, EGender gender, int age) : Npc{} {
        _lifeState = ELifeState::Alive;
        _race = ERace::Elf;
        _name = name;
        _gender = gender;
        _age = age;
        _life_span = ElfLifespan * (.8 + (rand() % 40) / 100.0);
        _isBreedable = true;
        _breedStartAge = 40;
        _breedStopAge = 400;
    }

    Elf(std::string name, EGender gender) : Elf{name, gender, 0} {
    }

    std::string say_hi() const override;

    std::string to_string() const override;

    void growOlder() override;

    void onKilled() override;

    int initNewRelation(Npc &npc) const override;

    int talkWith(Npc& npc) const override;

    bool canBreadWith(Npc& other) const override;

    static const std::string getNpcNameFile() {
        return "resources/npcNames/Elf.txt";
    }
};


#endif //TEST1_ELF_H
