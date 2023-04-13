//
// Created by ofgha on 23/02/23.
//

#ifndef TEST1_NPCRELATIONCOMPUTER_H
#define TEST1_NPCRELATIONCOMPUTER_H

#include "../Npc/Npc.h"
#include "RaceRelation.h"

class NpcRelationComputer {
public:
    int getNewRelation(Npc& npc1, Npc& npc2) {
        return _raceRelation.getRelation(npc1, npc2);
    }
private:
    RaceRelation _raceRelation;
};

#endif //TEST1_NPCRELATIONCOMPUTER_H
