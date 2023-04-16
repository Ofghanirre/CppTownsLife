//
// Created by Antonin on 16/04/2023.
//

#ifndef TEST1_ERACE_H
#define TEST1_ERACE_H

#include <string>
#include <vector>

using namespace std;

enum class ERace{
    Unknown = 0,
    Human,
    Elf,
    Undead,
    Spirit
};

namespace NpcRace {
    string to_string(ERace race);
    string getNameFilePath(ERace race);
    std::vector<ERace> getAll();
}



#endif //TEST1_ERACE_H
