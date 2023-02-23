//
// Created by ofgha on 16/02/23.
//

#ifndef TEST1_NPC_H
#define TEST1_NPC_H


#include <iostream>
#include <vector>

enum class ERace{
    UNKNOWN = 0,
    HUMAN,
    ELF,
    UNDEAD,
    SPIRIT
};
static std::string getRaceRepr(ERace race) {
    static std::vector<std::string> RaceRepr = {"UNKNOWN", "HUMAN", "ELF", "UNDEAD", "SPIRIT"};
    return RaceRepr[(int) race];
}


enum class EGender {
    UNKNOWN = 0,
    MALE,
    FEMALE
};
static std::string getGenderRepr(EGender gender) {
    static std::vector<std::string> GenderRepr = {"<?>", "\u2642", "\u2640"};
    return GenderRepr[(int) gender];
}

enum class ELifeState {
    DEAD = 0,
    ALIVE = 1,
    IMMORTAL = 2,

};
static std::string getLifeStateRepr(ELifeState lifeState) {
    static std::vector<std::string> LifeStateRepr = {"DEAD", "ALIVE", "IMMORTAL"};
    return LifeStateRepr[(int) lifeState];
}

static long _current_id = 0l;

class Npc {
public:
    virtual std::string say_hi() const = 0;

    virtual std::string to_string() const = 0;

    Npc() {
        _id = _current_id++;
//        std::cout << "++ NPC <" + std::to_string(getId()) + ">" << std::endl;
    }

    ~Npc() {
//        std::cout << "-- NPC <" + std::to_string(getId()) + ">" << std::endl;
    }

    long getId() const;

    virtual ELifeState getLifeState() const;

    virtual ERace getRace() const;

    virtual EGender getGender() const;

    virtual std::string getName() const;

    virtual int getAge() const;

    virtual int getLifeSpan() const;

    virtual bool isAlive() const;

    virtual int age() = 0;

    virtual void kill() = 0;
protected:
    long _id;

    ELifeState _lifeState;
    ERace _race;
    std::string _name;
    EGender _gender;
    int _age;
    int _life_span;


    /* SETTERS
     * Used for child Class implementations
     */
    void setLifeState(ELifeState lifeState);
    void setName(std::string name);
    void setRace(ERace race);
    void setGender(EGender gender);
    void setAge(int age);
};


#endif //TEST1_NPC_H
