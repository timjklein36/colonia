#include "Ant.h"

Ant::Ant() {
    this->setAlive(true);
    this->setMovementRate(8.0); // Ants move at 8 cm/s
}

const unsigned short Ant::getMaxEnergy() {
    return 100;
}

void Ant::tick(double deltaSeconds) {
    LOG(trace) << "Ant ticked. Delta Seconds: [" << deltaSeconds << "].";
}
