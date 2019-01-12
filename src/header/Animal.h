#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

#include "boost/log/trivial.hpp"

#include "Organism.h"
#include "Direction.h"

#define LOG BOOST_LOG_TRIVIAL

class Animal: public Organism {
    private:
        double movementRate; // centimeters per second

    public:
        void setMovementRate(double rate);
        const double getMovementRate();

        virtual void move(Direction direction, double deltaSeconds);
};

#endif
