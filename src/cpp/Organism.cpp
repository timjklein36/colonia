#include "Organism.h"

Organism::Organism() {
    this->aboveGroundLocation.x(0.0);
    this->aboveGroundLocation.y(0.0);
    this->underGroundLocation.x(0.0);
    this->underGroundLocation.y(0.0);
}

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

void Organism::setAboveGround(bool aboveGround) {
    this->aboveGround = aboveGround;
}

const bool Organism::isAboveGround() {
    return this->aboveGround;
}

void Organism::setAboveGroundLocation(Point loc) {
    this->aboveGroundLocation = loc;
}

const Point Organism::getAboveGroundLocation() {
    return this->aboveGroundLocation;
}

void Organism::setUnderGroundLocation(Point loc) {
    this->underGroundLocation = loc;
}

const Point Organism::getUnderGroundLocation() {
    return this->underGroundLocation;
}

std::ostream& operator<< (std::ostream& out, const Organism& organism) {
    out << "Alive: " << organism.alive << ", x=" << organism.aboveGroundLocation.x() << ", y=" << organism.aboveGroundLocation.y();
    return out;
}
