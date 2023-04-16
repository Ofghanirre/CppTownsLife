//
// Created by Antonin on 16/04/2023.
//

#ifndef TEST1_EPLAYERACTIONS_H
#define TEST1_EPLAYERACTIONS_H

#include <string>
#include <vector>
#include <functional>

using namespace std;

enum EPlayerActions {
    QUIT = -2,
    FINISH= -1,
    UNKNOWN  = 0,
    HELLO = 1
};

namespace PlayerActions {
    string to_string(EPlayerActions action);
    vector<EPlayerActions> getAll();
};

#endif //TEST1_EPLAYERACTIONS_H
