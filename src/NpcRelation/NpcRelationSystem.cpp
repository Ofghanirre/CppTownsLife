//
// Created by Antonin on 26/02/2023.
//

#include "NpcRelationSystem.h"


std::pair<long, long> getPair(Npc& npc1, Npc& npc2) {
    return std::pair<long, long>(npc1.getId(), npc2.getId());
}

int NpcRelationSystem::getRelationShip(Npc &npc, Npc &other) {
    auto relation = getPair(npc, other);
    if (_relationShip.find(relation) == _relationShip.end()) {
        initNewRelation(npc, other);
    }
    return _relationShip.at(relation);
}

void NpcRelationSystem::socialInteraction(Npc &npc, Npc &other) {
    auto relation1 = getPair(npc, other);
    auto relation2 = getPair(other, npc);

    if (_relationShip.find(relation1) == _relationShip.end()) {
        initNewRelation(npc, other);
    }
    if (_relationShip.find(relation2) == _relationShip.end()) {
        initNewRelation(other, npc);
    }

    _relationShip[relation1] += npc.talkWith(other);
    _relationShip[relation2] += other.talkWith(npc);

    if (_relationShip[relation1] >= 100 && _relationShip[relation2] >= 100) {
        std::cout << "A new couple has been created !\n" << npc.getName() << " and " << other.getName() << std::endl;
        _couples.emplace(npc.getId(), other.getId());
    }
}

void NpcRelationSystem::initNewRelation(Npc &npc, Npc &other) {
    _relationShip[getPair(npc, other)] = _relationComputer.getNewRelation(npc, other);
}

std::ostream &operator<<(std::ostream &stream, const NpcRelationSystem &village) {
    stream << "Relations:\t{" << village._relationShip.size() << "}\n";
    for (const auto &relation: village._relationShip) {
        stream << relation.first.first << " <-> " << relation.first.second << " : " << relation.second << "\n";
    }
    stream << "\n";
    return stream;
}
