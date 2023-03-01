//
// Created by ofgha on 23/02/23.
//

#include <sstream>
#include "Village.h"

Village::Village(const std::string& name, const int creation_date) : _name(name), _age(0), _creationDate{creation_date} {
    std::cout << "On the year " << creation_date << " a new community shine! " << "Behold the Village " << name << "!" << std::endl;
}

Village::~Village() {
    std::cout << "The Village " << _name << " has faded into darkness after " << _age << " years..." << std::endl;
}


void Village::nextYearHandler() {
    for (auto iterator = _inhabitants.begin(); iterator != _inhabitants.end();) {
        auto& npc = *iterator->second;
        npc.growOlder();

        if (!npc.isAlive()) {
            int npcAge= npc.getAge();
            int currentYear = _creationDate + _age;

            _memorials.emplace_back(NpcMemorial{npc.getName(), npcAge, currentYear - npcAge, currentYear});
            iterator = _inhabitants.erase(iterator);
            continue;
        }
        iterator++;
    }
    _age++;
}

int Village::getVillageSize() const {
    return _inhabitants.size();
}
int Village::getMemorialSize() const {
    return _memorials.size();
}

int Village::getAliveInhabitantsAmount() const {
    int result = 0;
    for (const auto &item: _inhabitants) {
        if (item.second->getLifeState() == ELifeState::Alive) {
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
        result << "* " << npc.second->to_string() << "\t[" << npc.second->getId() << "]" << "\n";
    }
    result << "Memorials:\t{" << getMemorialSize() << "}\n";
    for (const auto &deadNpc: _memorials) {
        result << "+ " << deadNpc._name << " : " << deadNpc._death_age << " | " << deadNpc.birth_date << " -*- " << deadNpc.death_date << "\n";
    }
    result << "Age : " << _age;

    result << "\n";

    result << _relationSystem;

    return result.str();
}

void Village::killAllInhabitants() {
    for (const auto &npc: _inhabitants) {
        npc.second->killHandler();
    }
}

std::string Village::getName() const {
    return _name;
}

std::ostream &operator<<(std::ostream &os, const Village &v) {
    os << v.to_string();
    return os;
}

VillageAction Village::talkAction() {
    long npc1, npc2;
    std::cout << "Enter first npc1 : ";
    std::cin >> npc1;
    std::cout << std::endl;
    std::cout << "Enter second npc2 : ";
    std::cin >> npc2;

    if (_inhabitants.find(npc1) == _inhabitants.end() || _inhabitants.find(npc2) == _inhabitants.end()) {
        std::cout << "Error, unknown Id" << std::endl ;
        return VillageAction::Unknown;
    }

    if (npc1 == npc2) {
        std::cout << "Error, schyzophrenia is still WIP" << std::endl;
        return VillageAction::Unknown;
    }

    this->_relationSystem.socialInteraction(*_inhabitants[npc1], *_inhabitants[npc2]);

    std::cout << (*_inhabitants[npc1]).getName() << " and " << (*_inhabitants[npc2]).getName()
              << " talked, their relation is now on : "
              <<  this->_relationSystem.getRelationShip(*_inhabitants[npc1], *_inhabitants[npc2])
              << std::endl;

    return VillageAction::Talk;
}

VillageAction Village::playAction() {
    int actionPrompt;
    std::cout << "Village " << getName() << "  - Action Handler\n"
    << "- 0 -   Exit\n"
    << "- 1 -   Show\n"
    << "- 2 -   Talk\n"
    << std::endl;

    std::cin >> actionPrompt;

    switch ((VillageAction) actionPrompt) {
        case VillageAction::Exit : {
            return VillageAction::Exit;
        }
        case VillageAction::Show : {
            std::cout << *this << std::endl;
            return VillageAction::Show;
        }
        case VillageAction::Talk : {
            return talkAction();
        }
        default: {
            return VillageAction::Unknown;
        }
    }
}



