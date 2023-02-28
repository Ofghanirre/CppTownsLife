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
    auto relation = getPair(npc, other);
    if (_relationShip.find(relation) == _relationShip.end()) {
        initNewRelation(npc, other);
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
