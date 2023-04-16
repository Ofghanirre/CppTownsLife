//
// Created by Antonin on 16/04/2023.
//

#include "EPlayerActions.h"

namespace PlayerActions {
    std::string to_string(EPlayerActions gender) {
        switch (gender) {
            case EPlayerActions::QUIT :
                return "QUIT";
            case EPlayerActions::FINISH :
                return "FINISH";
            case EPlayerActions::HELLO :
                return "HELLO";
            default :
                return "UNKNOWN";
        }
    }

    std::vector<EPlayerActions> getAll() {
        static auto registered = {EPlayerActions::QUIT, EPlayerActions::FINISH, EPlayerActions::HELLO};
        return registered;
    }
}



