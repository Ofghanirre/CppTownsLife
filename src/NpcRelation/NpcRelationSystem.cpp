//
// Created by Antonin on 26/02/2023.
//

#include "NpcRelationSystem.h"
#include "../Npc/Races/Human/Human.h"
#include "../Npc/Races/Elf/Elf.h"

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

    if ((npc.getGender() != other.getGender()) && _relationShip[relation1] >= 100 && _relationShip[relation2] >= 100) {
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

    stream << "Couples:\t{" << village._couples.size() << "}\n";
    for (const auto &couple: village._couples) {
        auto pair = couple.getCouple();
        stream << pair.first << " - in love with - " << pair.second << "\n";
    }
    stream << "\n";
    return stream;
}

std::unique_ptr<Npc> NpcRelationSystem::makeBaby(const Npc &parent1, const Npc &parent2) {
    EGender childGender = (rand() % 2) ? EGender::Female : EGender::Male;
    ERace childRace = (rand() % 2) ? parent1.getRace() : parent2.getRace();
    std::string childName = parent1.getName().substr(0, parent1.getName().size() / 2) + parent2.getName().substr(parent2.getName().size() / 2, parent2.getName().size());
    switch (childRace ) {
        case ERace::Human : {
            return std::make_unique<Human>(childName, childGender, 0);
        }
        case ERace::Elf : {
            return std::make_unique<Elf>(childName, childGender, 0);
        }
        default: {
            throw std::invalid_argument("The race " + getRaceRepr(childRace) + " has no implementation for child making");
        }
    }
}

const std::unordered_set<NpcCouple> &NpcRelationSystem::getCouples() const {
    return _couples;
}
