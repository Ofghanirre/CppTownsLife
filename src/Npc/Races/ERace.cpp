//
// Created by Antonin on 16/04/2023.
//

#include "ERace.h"

namespace NpcRace {
    string to_string(ERace race) {
        switch (race) {
            case ERace::Human       :
                return "HUMAN";
            case ERace::Elf         :
                return "ELF";
            case ERace::Undead      :
                return "UNDEAD";
            case ERace::Spirit      :
                return "SPIRIT";
            default                 :
                return "UNKNOWN";
        }
    }

    std::vector<ERace> getAll() {
        static auto registered = {ERace::Human, ERace::Elf, ERace::Undead, ERace::Spirit};
        return registered;
    }

    string getNameFilePath(ERace race) {
        switch (race) {
            case ERace::Human       :
                return "resources/npcNames/Human.txt";
            case ERace::Elf         :
                return "resources/npcNames/Elf.txt";
            case ERace::Undead      :
                return "resources/npcNames/Undead.txt";
            case ERace::Spirit      :
                return "resources/npcNames/Spirit.txt";
            default                 :
                return "resources/npcNames/Default.txt";
        }
    }
}