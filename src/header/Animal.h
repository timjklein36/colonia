#ifndef ANIMAL_H
#define ANIMAL_H

#include "Organism.h"

class Animal: public Organism {
    private:
        double movementRate; // centimeters per second

    public:
        void setMovementRate(double rate);
        double getMovementRate();
};

#endif
