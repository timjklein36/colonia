#ifndef SIMULATION_RUNNER_H
#define SIMULATION_RUNNER_H

#include <memory>

#include "boost/log/trivial.hpp"

#include "Simulation.h"

#define LOG BOOST_LOG_TRIVIAL

class SimulationRunner {
    private:
        std::unique_ptr<Simulation> simulation;

    protected:
        virtual void startSimulation();
        virtual void stopSimulation();
        virtual void resetSimulation();

        virtual void tick();

    public:
        void setSimulation(std::unique_ptr<Simulation> simulation);
        std::unique_ptr<Simulation>& getSimulation();

        virtual void run() = 0;
};

#endif
