#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <memory>

#include "boost/log/trivial.hpp"

#include "Colony.h"

#define LOG BOOST_LOG_TRIVIAL

class Simulation {
    private:
        std::vector<std::unique_ptr<Colony>> colonies;
        short max_colonies;
        unsigned long max_duration; // Milliseconds
        bool running;

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

        void tick();

        bool isRunning();

        friend std::ostream& operator<< (std::ostream& out, const Simulation& sim);
};

#endif