//
// Created by ofgha on 16/02/23.
//

#ifndef TEST1_NPC_H
#define TEST1_NPC_H


#include <iostream>
#include <vector>
#include <map>
#include <memory>

enum class ERace{
    Unknown = 0,
    Human,
    Elf,
    Undead,
    Spirit
};
inline std::string getRaceRepr(ERace race) {
    switch (race) {
        case ERace::Human       : return "HUMAN";
        case ERace::Elf         : return "ELF";
        case ERace::Undead      : return "UNDEAD";
        case ERace::Spirit      : return "SPIRIT";
        default                 : return "UNKNOWN";
    }
}

enum class EGender {
    Unknown = 0,
    Male,
    Female
};
inline std::string getGenderRepr(EGender gender) {
    switch (gender) {
        case EGender::Male          : return "\u2642";
        case EGender::Female        : return "\u2640";
        default                     : return "<?>";
    }
}

enum class ELifeState {
    Dead = 0,
    Alive = 1,
    Immortal = 2,
};
inline std::string getLifeStateRepr(ELifeState lifeState) {
    switch (lifeState) {
        case ELifeState::Dead       : return "DEAD";
        case ELifeState::Alive      : return "ALIVE";
        case ELifeState::Immortal   : return "IMMORTAL";
    }
}


class Npc {
private:
    static inline size_t _current_id = 0l;

public:
    virtual std::string say_hi() const = 0;
    virtual std::string to_string() const = 0;
    virtual void growOlder() = 0;
    virtual void onKilled() = 0;
    virtual int talkWith(Npc& npc) const = 0;

    Npc() {
        _id = _current_id++;
//        std::cout << "++ NPC <" + std::to_string(getId()) + ">" << std::endl;
    }

    virtual ~Npc() {
//        std::cout << "-- NPC <" + std::to_string(getId()) + ">" << std::endl;
    }

    virtual bool isAlive() const;
    void killHandler();
    virtual bool canBreadWith(Npc& other) const;

    long getId() const;
    ELifeState getLifeState() const;
    ERace getRace() const;
    EGender getGender() const;
    std::string getName() const;
    int getAge() const;
    int getLifeSpan() const;
    bool isBreedable() const;


    bool operator==(const Npc& other) const;

protected:
    long _id = 0;

    ELifeState _lifeState = ELifeState::Immortal;
    ERace _race = ERace::Unknown;
    std::string _name;
    EGender _gender = EGender::Unknown;
    int _age = 0;
    int _life_span = 0;
    bool _isBreedable;

    virtual int initNewRelation(Npc& npc) const = 0;

    /* SETTERS
     * Used for child Class implementations
     */
    void setLifeState(ELifeState lifeState);
    void setName(std::string name);
    void setRace(ERace race);
    void setGender(EGender gender);
    void setAge(int age);
    void setLifeSpan(int lifespan);
};

#endif //TEST1_NPC_H
