//
// Created by Antonin on 16/04/2023.
//

#ifndef TEST1_ELIFESTATE_H
#define TEST1_ELIFESTATE_H

#include <string>
#include <vector>

using namespace std;

enum class ELifeState {
    Dead = 0,
    Alive = 1,
    Immortal = 2,
};
namespace NpcLifeState {
    std::string to_string(ELifeState lifeState);

    std::vector<ELifeState> getAll();

} // NpcLifeState

#endif //TEST1_ELIFESTATE_H
