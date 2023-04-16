//
// Created by Antonin on 16/04/2023.
//

#include "EGender.h"

namespace NpcGender {

    std::string to_string(EGender gender) {
        switch (gender) {
            case EGender::Male          : return "MALE";
            case EGender::Female        : return "FEMALE";
            default                     : return "<?>";
        }
    }

    std::vector<EGender> getAll() {
        static auto registered = {EGender::Male, EGender::Female};
        return registered;
    }
} // NpcGender