//
// Created by ofgha on 23/02/23.
//

#ifndef TEST1_NPCRELATION_H
#define TEST1_NPCRELATION_H

#include "../Npc.h"

class NpcRelation {
protected:
    virtual int getRelation(Npc& npc1, Npc& npc2) const = 0;
};

#endif //TEST1_NPCRELATION_H
