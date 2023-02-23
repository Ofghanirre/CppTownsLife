//
// Created by ofgha on 23/02/23.
//

#ifndef TEST1_RACERELATION_H
#define TEST1_RACERELATION_H
#include <unordered_map>
#include "../Npc.h"
#include "NpcRelation.h"

static const std::unordered_map<ERace, std::unordered_map<ERace, int>> raceOpinion{
        {
            /* HUMAN RELATIONS */
            ERace::Human,  {
                // Default
                {ERace::Unknown,     0},
                // Others:
                {ERace::Human,     0},
                {ERace::Elf,     -5},
                {ERace::Undead,     -20},
                {ERace::Spirit,     5}
            }
        },
        {
            /* ELF RELATIONS */
            ERace::Elf,    {
                // Default
                {ERace::Unknown,     0},
                // Others:
                {ERace::Human,     -10},
                {ERace::Elf,     10},
                {ERace::Undead,     -20},
                {ERace::Spirit,     50}
            }
        },
        {
            /* SPIRIT RELATIONS */
            ERace::Spirit, {
                // Default
                {ERace::Unknown,     0},
                // Others:
                {ERace::Human,     10},
                {ERace::Elf,     25},
                {ERace::Undead,     -20},
                {ERace::Spirit,     100}
            }
        },
        {
            /* UNDEAD RELATIONS */
            ERace::Undead, {
                    // Default
                    {ERace::Unknown, 0},
                    // Others:
                    {ERace::Human, -10},
                    {ERace::Elf, -10},
                    {ERace::Undead, -10},
                    {ERace::Spirit, -10}
            }
        }
};

class RaceRelation : NpcRelation {
public:
    int getRelation(Npc& main, Npc& other) const override {
        auto mainData = raceOpinion.find(main.getRace());
        if (mainData != raceOpinion.end()) {
            auto mainRelation = mainData->second;
            auto result = mainRelation.find(other.getRace());
            if (result != mainRelation.end()) {
                return result->second;
            }
            return mainRelation.find(ERace::Unknown)->second;
        }
        return 0;
    }
};

#endif //TEST1_RACERELATION_H
