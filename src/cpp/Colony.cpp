#include "Colony.h"

Colony::Colony() {}

void Colony::addMember(Organism& member) {
    this->members.push_back(member);
}

const std::vector<Organism> Colony::getMembers() {
    return this->members;
}
