//
// Created by Antonin on 26/02/2023.
//

#ifndef TEST1_NPCRELATIONSYSTEM_H
#define TEST1_NPCRELATIONSYSTEM_H


#include <map>
#include <unordered_set>
#include <memory>
#include "../Npc/Npc.h"
#include "NpcRelationComputer.h"
#include "NpcCouple/NpcCouple.h"

class NpcRelationSystem {
public:
    void socialInteraction(Npc& npc, Npc& other);

    int getRelationShip(Npc& npc, Npc& other);

    friend std::ostream& operator<<(std::ostream& stream, const NpcRelationSystem& village);

    const std::unordered_set<NpcCouple>& getCouples() const;

    std::unique_ptr<Npc> makeBaby(const Npc& parent1, const Npc& parent2);

private:
    NpcRelationComputer _relationComputer;
    std::map<std::pair<long, long>, int> _relationShip;
    std::unordered_set<NpcCouple> _couples;

    void initNewRelation(Npc& npc, Npc& other);
};


#endif //TEST1_NPCRELATIONSYSTEM_H
