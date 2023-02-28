//
// Created by ofgha on 21/02/23.
//

#include "Npc.h"

bool Npc::isAlive() const {
    return _lifeState != ELifeState::Dead;
}

long Npc::getId() const {
    return _id;
}

ELifeState Npc::getLifeState() const {
    return _lifeState;
}

ERace Npc::getRace() const {
    return _race;
}

EGender Npc::getGender() const {
    return _gender;
}

std::string Npc::getName() const {
    return _name;
}

int Npc::getAge() const {
    return _age;
}

int Npc::getLifeSpan() const {
    return _life_span;
}

void Npc::setName(std::string name) {
    _name = name;
}

void Npc::setRace(ERace race) {
    _race = race;
}

void Npc::setGender(EGender gender) {
    _gender = gender;
}

void Npc::setLifeState(ELifeState lifeState) {
    _lifeState = lifeState;
}

void Npc::setAge(int age) {
    _age = age;
}

void Npc::setLifeSpan(int lifespan) {
    _life_span = lifespan;
}

void Npc::killHandler() {
    _lifeState = ELifeState::Dead;
    onKilled();
}

void Npc::talkWith(Npc &npc) {
    std::cout << this->getName() << " interacts with " << npc.getName() << std::endl;
    socialInteraction(npc);
    std::cout << "Interaction finished !\n" << "Relation between " << this->getName() << " and " << npc.getName()
    << " are now at " << getRelationWith(npc) << std::endl;
}

int Npc::getRelationWith(Npc &npc) {
    if (_relationShips.find(npc.getId()) == _relationShips.end()) {
        initNewRelation(npc);
    }
    return _relationShips.at(npc.getId());
}









