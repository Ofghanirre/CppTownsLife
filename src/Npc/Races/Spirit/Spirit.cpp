//
// Created by ofgha on 22/02/23.
//

#include "Spirit.h"

std::string Spirit::to_string() const {
    return "["+ getRaceRepr(_race) +" "+ getGenderRepr(_gender) + " ] " + _name ;
}

std::string Spirit::say_hi() const {
    if (getLifeState() == ELifeState::Alive)
        return to_string() + " :\n\t *Smile gently*";
    return to_string() + " is dead and thus can not answer...";
}

void Spirit::growOlder() {
}

void Spirit::onKilled() {
    std::cout << to_string() + " faded away into unknown realms..." << std::endl;
}

int Spirit::initNewRelation(Npc &npc) const {
    return 0;
}

void Spirit::socialInteraction(Npc &other) {

}
