//
// Created by ofgha on 23/02/23.
//

#ifndef TEST1_VILLAGE_H
#define TEST1_VILLAGE_H


#include <vector>
#include <memory>
#include "../Npc/Npc.h"

struct NpcMemorial {
    NpcMemorial(std::string name, int death_age, const int birthDate, const int deathDate)
        : _name{name}, _death_age{death_age}, birth_date(birthDate), death_date(deathDate) {
    }

    const std::string _name;
    const int _death_age;
    const int birth_date;
    const int death_date;
};

class Village {
public:
    explicit Village(const std::string name, const int creation_date);

~Village();

    int getVillageSize() const;

    int getMemorialSize() const;


    int addNpc(std::unique_ptr<Npc> npc) {
        _inhabitants.emplace_back(std::move(npc));
        return _inhabitants.size();
    }

    int getAliveInhabitants() const;

    int age();

    void kill();

    std::string to_string() const;

    std::string getName() const;

private:
    const std::string _name;
    int _age;
    int _creationDate;
    std::vector<NpcMemorial> _memorials;
    std::vector<std::unique_ptr<Npc>> _inhabitants;

};


#endif //TEST1_VILLAGE_H
