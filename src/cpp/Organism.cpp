#include "Organism.h"

const bool Organism::isAlive() {
    return this->alive;
}

void Organism::setAlive(bool alive) {
    this->alive = alive;
}

void Organism::setEnergy(unsigned short energy) {
    if (energy < this->getMaxEnergy()) {
        this->energy = energy;
    } else {
        this->energy = this->getMaxEnergy();
    }
}

const unsigned short Organism::getEnergy() {
    return this->energy;
}

std::ostream& operator<< (std::ostream& out, const Organism& organism) {
    out << organism.alive;
    return out;
}
