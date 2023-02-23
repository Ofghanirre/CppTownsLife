//
// Created by ofgha on 23/02/23.
//

#ifndef TEST1_VILLAGE_H
#define TEST1_VILLAGE_H


#include <utility>
#include <vector>
#include <memory>
#include "../Npc/Npc.h"

struct NpcMemorial {
    std::string _name;
    int _death_age;
    int birth_date;
    int death_date;
};

class Village {
public:
    explicit Village(const std::string& name, const int creation_date);

~Village();

    int getVillageSize() const;

    int getMemorialSize() const;


    int addNpc(std::unique_ptr<Npc> npc) {
        _inhabitants.emplace_back(std::move(npc));
        return _inhabitants.size();
    }

    int getAliveInhabitantsAmount() const;

    void nextYearHandler();

    void killAllInhabitants();

    std::string to_string() const;

    std::string getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Village& v);

private:
    const std::string _name;
    int _age;
    int _creationDate;
    std::vector<NpcMemorial> _memorials;
    std::vector<std::unique_ptr<Npc>> _inhabitants;

};


#endif //TEST1_VILLAGE_H
