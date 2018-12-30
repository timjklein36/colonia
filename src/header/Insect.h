#ifndef INSECT_H
#define INSECT_H

#include "Organism.h"

class Insect: public Organism {
    private:

    protected:
        Insect();

    public:
        const bool isMolting();
};

#endif