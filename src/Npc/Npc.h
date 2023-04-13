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

inline std::vector<ERace> getAllRace() {
    return {ERace::Human, ERace::Elf, ERace::Undead, ERace::Spirit};
}

enum class EGender {
    Unknown = 0,
    Male,
    Female
};
inline std::string getGenderRepr(EGender gender) {
    switch (gender) {
        case EGender::Male          : return "MALE";
        case EGender::Female        : return "FEMALE";
        default                     : return "<?>";
    }
}

inline std::vector<EGender> getAllGender() {
    return {EGender::Male, EGender::Female};
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
        // For ownership debug
        //        std::cout << "++ NPC <" + std::to_string(getId()) + ">" << std::endl;
    }

    virtual ~Npc() {
        // For ownership debug
        //std::cout << "-- NPC <" + std::to_string(getId()) + ">" << std::endl;
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
    bool _isBreedable = false;
    int _breedStartAge = 0;
    int _breedStopAge = 0;

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
