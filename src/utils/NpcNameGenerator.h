//
// Created by Antonin on 15/04/2023.
//

#ifndef TEST1_NPCNAMEGENERATOR_H
#define TEST1_NPCNAMEGENERATOR_H


#include "../Npc/Npc.h"
using namespace std;

class NpcNameGenerator {
public:
    static string generateNewName(ERace race, int syllablesMinLength, int syllablesMaxLength);
private:
    static map<ERace, vector<string>> init();
    static map<ERace, vector<string>> _names;
    static const map<string, string> _placeholders;

    static std::vector<std::string> readSyllablesFromFile(const string &filePath);
};


inline const map<string, string> NpcNameGenerator::_placeholders{
        {"%space%", " "}
};



#endif //TEST1_NPCNAMEGENERATOR_H
