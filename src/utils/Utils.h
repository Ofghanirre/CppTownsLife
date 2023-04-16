//
// Created by Antonin on 15/04/2023.
//

#ifndef TEST1_UTILS_H
#define TEST1_UTILS_H

#include <random>
#include <fstream>

#include "Displayer.h"
#include "RpgDate.h"
#include "NpcNameGenerator.h"

#include "../Npc/Npc.h"
#include "../Npc/Races/Human/Human.h"
#include "../Npc/Races/Elf/Elf.h"
#include "../Npc/Races/Undead/Undead.h"
#include "../Npc/Races/Spirit/Spirit.h"

using namespace std;

int random_between(int a, int b);

std::vector<std::string> readSyllablesFromFile(const std::string& filePath);
std::string getFilePathFromRace(ERace race);
std::string generateNewName(ERace race, int syllablesMinLength, int syllablesMaxLength);

#endif //TEST1_UTILS_H
