#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>

#include "Colony.h"

class Simulation {
    private:
        std::vector<Colony> colonies;

    public:
        Simulation();

        void addColony(Colony& colony);
        const std::vector<Colony> getColonies();

        void start();
        void stop();
        void reset();

        friend std::ostream& operator<< (std::ostream& out, const Simulation& sim);
};

#endif