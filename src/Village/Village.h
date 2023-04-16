//
// Created by ofgha on 23/02/23.
//

#ifndef TEST1_VILLAGE_H
#define TEST1_VILLAGE_H


#include <utility>
#include <vector>
#include <memory>
#include "../Npc/Npc.h"
#include "../NpcRelation/NpcRelationSystem.h"
#include "../Logger/Logger.h"

struct NpcMemorial {
    std::string _name;
    int _death_age;
    int birth_date;
    int death_date;
};

enum class VillageAction {
    Unknown = -1,
    Exit = 0,
    None = 1,
    Show = 2,
    Talk = 3,
};


using NpcMemorials = std::vector<NpcMemorial>;
using NpcMap = std::map<long, std::unique_ptr<Npc>>;

class Village {
public:
    explicit Village(const std::string& name, const int creation_date);
    explicit Village(const Village& pVillage);

//    static Village* createVillage(const std::string& name, const int creation_date) {
//        Village* result = new Village(name, creation_date);
//        result->_relationSystem = {result};
//        return result;
//    }
~Village();

    int getVillageSize() const;

    int getMemorialSize() const;


    int addNpc(std::unique_ptr<Npc> npc) {
        _inhabitants[npc->getId()] = std::move(npc);
        return _inhabitants.size();
    }

    Npc & getNpc(long);

    int getAliveInhabitantsAmount() const;
    int getCreationDate() const;

    void nextYearHandler();

    void killAllInhabitants();

    std::string to_string() const;

    std::string getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Village& v);

    VillageAction playAction();

    friend std::ostream& operator<<(std::ostream& stream, const Village& village);
private:

    const std::string _name;
    int _age;
    int _creationDate;
    NpcMemorials _memorials;
    NpcMap _inhabitants;

    NpcRelationSystem _relationSystem;
    Logger _logger;

    VillageAction talkAction();
};


#endif //TEST1_VILLAGE_H
