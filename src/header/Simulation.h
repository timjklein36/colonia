#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <memory>

#include "Colony.h"

class Simulation {
    private:
        std::vector<std::unique_ptr<Colony>> colonies;

    public:
        explicit Simulation();

        Simulation(const Simulation&) = delete;
        Simulation& operator= (const Simulation&) = delete;

        Simulation(Simulation&& simulation);

        ~Simulation() = default;

        void addColony(std::unique_ptr<Colony> colony);
        const std::vector<std::unique_ptr<Colony>>& getColonies();

        void start();
        void stop();
        void reset();

        friend std::ostream& operator<< (std::ostream& out, const Simulation& sim);
};

#endif