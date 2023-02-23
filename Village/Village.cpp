//
// Created by ofgha on 23/02/23.
//

#include <sstream>
#include "Village.h"

Village::Village(const std::string name, const int creation_date) : _name(name), _age(0), _creationDate{creation_date} {
    std::cout << "On the year " << creation_date << " a new community shine! " << "Behold the Village " << name << "!" << std::endl;
}

Village::~Village() {
    std::cout << "The Village " << _name << " has faded into darkness after " << _age << " years..." << std::endl;
}


int Village::age() {
    for (auto iterator = _inhabitants.begin(); iterator != _inhabitants.end();) {
        int npcAge= (*iterator)->age();

        if (!(*iterator)->isAlive()) {
            int currentYear = _creationDate + _age;

            _memorials.emplace_back((*iterator)->getName(), npcAge, currentYear - npcAge, currentYear);
            iterator = _inhabitants.erase(iterator);
            continue;
        }
        iterator++;
    }
    _age++;
    return _inhabitants.size();
}

int Village::getVillageSize() const {
    return _inhabitants.size();
}
int Village::getMemorialSize() const {
    return _memorials.size();
}

int Village::getAliveInhabitants() const {
    int result = 0;
    for (const auto &item: _inhabitants) {
        if (item->getLifeState() == ELifeState::ALIVE) {
            result++;
        }
    }
    return result;
}


std::string Village::to_string() const {
    std::stringstream result;
    result << "Village " << _name << " informations:\n";
    result << "Inhabitants:\t{" << getVillageSize() << "}\n";
    for (const auto &npc: _inhabitants) {
        result << "* " << npc->to_string() << "\n";
    }
    result << "Memorials:\t{" << getMemorialSize() << "}\n";
    for (const auto &deadNpc: _memorials) {
        result << "+ " << deadNpc._name << " : " << deadNpc._death_age << " | " << deadNpc.birth_date << " -*- " << deadNpc.death_date << "\n";
    }
    result << "Age : " << _age;

    return result.str();
}

void Village::kill() {
    for (const auto &npc: _inhabitants) {
        npc->kill();
    }
}

std::string Village::getName() const {
    return _name;
}


