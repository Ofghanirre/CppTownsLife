//
// Created by Antonin on 16/04/2023.
//

#include "ELifeState.h"

namespace NpcLifeState {
    std::string to_string(ELifeState lifeState) {
        switch (lifeState) {
            case ELifeState::Dead       : return "DEAD";
            case ELifeState::Alive      : return "ALIVE";
            case ELifeState::Immortal   : return "IMMORTAL";
            default: return "UNKNOWN";
        }
    }

    std::vector<ELifeState> getAll() {
        static auto registered =  {ELifeState::Alive, ELifeState::Dead, ELifeState::Immortal};
        return registered;
    }
} // NpcLifeState