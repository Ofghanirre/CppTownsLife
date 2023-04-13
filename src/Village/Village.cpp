//
// Created by ofgha on 23/02/23.
//

#include <sstream>
#include "Village.h"

Village::Village(const std::string& name, const int creation_date) : _name(name), _age(0), _creationDate{creation_date},
                                                                     _logger("Village " + name)
{
    _logger.logln(LogLevel::Info, "New Village");
    std::cout << "On the year " << creation_date << " a new community shine! " << "Behold the Village " << name << "!" << std::endl;
}

Village::Village(const Village &pVillage) : Village(pVillage._name, pVillage._creationDate){}


Village::~Village() {
    _logger.logln(LogLevel::Info, "End Village");
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

    for (const auto &couple: _relationSystem.getCouples()) {
        auto pair = couple.getCouple();
        if (( rand() % 100 ) != 42) {
            auto child = _relationSystem.makeBaby(*_inhabitants[pair.first], *_inhabitants[pair.second]);
            _logger.logln(LogLevel::Info, "New Child");
            std::cout << _inhabitants.at(pair.first)->getName() + " and " +  _inhabitants.at(pair.second)->getName() +" gave birth to " + child->getName() + "!" << std::endl;
            _inhabitants.emplace(child->getId(), std::move(child));
        }

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
    result << "Age : " << _age << "\n\n";

    result << "Inhabitants:\t{" << getVillageSize() << "}\n";
    for (const auto &npc: _inhabitants) {
        result << "-*- <" << npc.second->getId() << "> : " + npc.second->to_string() << "\n";
    }
    result << "---\n";
    result << "Memorials:\t{" << getMemorialSize() << "}\n";
    for (const auto &deadNpc: _memorials) {
        result << "+ " << deadNpc._name << " : " << deadNpc._death_age << " | " << deadNpc.birth_date << " -*- " << deadNpc.death_date << "\n";
    }
    result << "---\n";
    result << _relationSystem  << "\n";
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

Npc& Village::getNpc(long npcId) {
    if (_inhabitants.find(npcId) == _inhabitants.end()) {
        throw std::invalid_argument("Id " + std::to_string(npcId) + " invalid.");
    }
    return *_inhabitants.at(npcId);
}



// TODO implements actions in another class : VillageActionSystem
VillageAction Village::talkAction() {
    long npc1, npc2;
    _logger.logln(LogLevel::Info, "Social Interaction Selection")
    << "Input the id of the 2 npcs for the discussion.\n"
    << "Npc 1 >";
    std::cin >> npc1;
    std::cout << "\nNpc 2 >";
    std::cin >> npc2;
    std::cout << std::endl;

    if (_inhabitants.find(npc1) == _inhabitants.end() || _inhabitants.find(npc2) == _inhabitants.end()) {
        _logger.logln(LogLevel::Error, "Id unknown");
        return VillageAction::Unknown;
    }

    if (npc1 == npc2) {
        _logger.logln(LogLevel::Error, "Schizophrenia still WIP");
        return VillageAction::Unknown;
    }

    std::string npc1Name = (*_inhabitants[npc1]).getName();
    std::string npc2Name = (*_inhabitants[npc2]).getName();


    this->_relationSystem.socialInteraction(*_inhabitants[npc1], *_inhabitants[npc2]);
    _logger.logln(LogLevel::Info, "Social Interaction");
    std::cout << npc1Name << " and " << npc2Name
              << " talked, their relation improved !\n"
              << npc1Name + " -> " + npc2Name + " : " << this->_relationSystem.getRelationShip(*_inhabitants[npc1], *_inhabitants[npc2]) << "\n"
              << npc2Name + " -> " + npc1Name + " : " << this->_relationSystem.getRelationShip(*_inhabitants[npc2], *_inhabitants[npc1])
              << std::endl;

    return VillageAction::Talk;
}

VillageAction Village::playAction() {
    int actionPrompt;
    std::cout << "-*-" << std::endl;
    _logger.logln(LogLevel::Info, "Action Handler");
    std::cout
    << "- 0 -   Exit\t" << "- 1 -   None\t" << "- 2 -   Show\t" << "- 3 -   Talk\t"
    << "\n"
    << "Your Choice > ";
    std::cin >> actionPrompt;
    std::cout << std::endl;

    VillageAction result;

    switch ((VillageAction) actionPrompt) {
        case VillageAction::Exit : {
            result = VillageAction::Exit;
            break;
        }
        case VillageAction::None : {
            result = VillageAction::None;
            break;
        }
        case VillageAction::Show : {
            _logger.logln(LogLevel::Info, "Village Information");
            std::cout << *this << std::endl;
            result =  VillageAction::Show;
            break;
        }
        case VillageAction::Talk : {
            result = talkAction();
            break;
        }
        default: {
            result = VillageAction::Unknown;
        }
    }
    std::cout << "-*-" << std::endl;
    return result;
}

int Village::getCreationDate() const {
    return _creationDate;
}



