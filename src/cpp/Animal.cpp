#include "Animal.h"

void Animal::setMovementRate(double rate) {
    this->movementRate = rate;
}

const double Animal::getMovementRate() {
    return this->movementRate;
}

void Animal::move(Direction direction, double deltaSeconds) {
    double moveDistance = this->movementRate * deltaSeconds;

    Point location;
    std::string area;

    if (this->isAboveGround()) {
        location = this->aboveGroundLocation;
        area = "AboveGround";
    } else {
        location = this->underGroundLocation;
        area = "UnderGround";
    }

    LOG(trace) << "Moving Animal " << area << " from (" << location.x() << ", " << location.y() << ") by " << moveDistance << "cm in " << direction::directionToString(direction);

    switch (direction) {
        case POS_X:
            location.x(location.x() + moveDistance);
            break;
        case POS_Y:
            location.y(location.y() + moveDistance);
            break;
        case NEG_X:
            location.x(location.x() - moveDistance);
            break;
        case NEG_Y:
            location.y(location.y() - moveDistance);
            break;
    }

    LOG(trace) << "Animal now" << area << " at (" << location.x() << ", " << location.y() << ")";

    if (this->isAboveGround()) {
        this->setAboveGroundLocation(location);
    } else {
        this->setUnderGroundLocation(location);
    }
}
