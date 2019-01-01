#include "Ant.h"

Ant::Ant() {
    this->setMovementRate(8.0);
}

const unsigned short Ant::getMaxEnergy() {
    return 100;
}

void Ant::tick(double deltaSeconds) {
    LOG(trace) << "Ant ticked. Delta Seconds: [" << deltaSeconds << "].";
}
