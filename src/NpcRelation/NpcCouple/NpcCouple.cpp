//
// Created by Antonin on 01/03/2023.
//

#include "NpcCouple.h"

std::pair<long, long> NpcCouple::getCouple() const {
    return {_idMate1, _idMate2};
}
