//
// Created by Antonin on 15/04/2023.
//

#include "NpcNameGenerator.h"
#include "Utils.h"

std::vector<std::string> NpcNameGenerator::readSyllablesFromFile(const string &filePath) {
    std::vector<std::string> syllables;
    std::ifstream file(filePath);
    static const Logger logger{"NpcName loader"};
    if (!file.is_open()) {
        logger.log(LogLevel::Warning, "Unable to find " + filePath + " name file, loading default one instead...");
        file.open(Npc::getNpcNameFile());
        if (!file.is_open()) {
            logger.log(LogLevel::Error, "Unable to find " + Npc::getNpcNameFile() + " default name file... exiting");
            throw runtime_error("Unable to open NameFile : " + Npc::getNpcNameFile());
        }
    }
    std::string syllable;
    while (getline(file, syllable)) {
        auto s = remove(syllable.begin(), syllable.end(), '\r');    // IF CRLF FORMAT
        syllable.erase(s, syllable.end());                                                  // delete \r end
        if (_placeholders.contains(syllable)) {
            syllables.push_back(_placeholders.at(syllable));
        } else syllables.push_back(syllable);
    }
    file.close();
    return syllables;
}

std::string getFilePathFromRace(ERace race) {
    std::string racePathFile;
    switch (race) {
        case ERace::Human: racePathFile = Human::getNpcNameFile(); break;
        case ERace::Elf: racePathFile = Elf::getNpcNameFile(); break;
        case ERace::Undead: racePathFile = Undead::getNpcNameFile(); break;
        case ERace::Spirit: racePathFile = Spirit::getNpcNameFile(); break;
        default: racePathFile = Npc::getNpcNameFile();
    }
    const std::string absPath(__FILE__);
    const std::string baseDir = absPath.substr(0, absPath.find_last_of("/\\") + 1);
    return baseDir + "../../" + racePathFile;
}

std::string generateRandomName(ERace race, const int numSyllables, const std::vector<std::string>& syllables) {
    std::string name;
    std::string s;
    for (int i = 0; i < numSyllables; i++) {
        int randomIndex;
        do {
            randomIndex = random_between(0, syllables.size());
            s = syllables[randomIndex];
        } while ((i == 0 || i == numSyllables - 1) && (s == " " || s == "-"));
        name += s;
    }
    return name;
}

string NpcNameGenerator::generateNewName(ERace race, int syllablesMinLength, int syllablesMaxLength) {
    return generateRandomName(race, random_between(syllablesMinLength, syllablesMaxLength), _names.at(race));
}

map<ERace, vector<std::string>> NpcNameGenerator::init() {
    auto result = map<ERace, vector<string>>();
    for (const auto &race: getAllRace()) {
        result[race] = readSyllablesFromFile(getFilePathFromRace(race));
    }
    result[ERace::Unknown] = readSyllablesFromFile(getFilePathFromRace(ERace::Unknown));
    return result;
}

map<ERace, vector<string>> NpcNameGenerator::_names = NpcNameGenerator::init();