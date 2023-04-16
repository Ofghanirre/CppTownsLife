//
// Created by Antonin on 15/04/2023.
//

#include "Utils.h"


int random_between(int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b-1);
    return dis(gen);
}
