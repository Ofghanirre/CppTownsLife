//
// Created by Antonin on 16/04/2023.
//

#ifndef TEST1_EGENDER_H
#define TEST1_EGENDER_H

#include <string>
#include <vector>

using namespace  std;

enum class EGender {
    Unknown = 0,
    Male,
    Female
};

namespace NpcGender {
    std::string to_string(EGender gender);
    std::vector<EGender> getAll();
} // NpcGender

#endif //TEST1_EGENDER_H
