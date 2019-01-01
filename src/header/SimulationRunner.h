#ifndef SIMULATION_RUNNER_H
#define SIMULATION_RUNNER_H

#include <memory>

#include "boost/log/trivial.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

#include "Simulation.h"

#define LOG BOOST_LOG_TRIVIAL

class SimulationRunner {
    private:
        std::unique_ptr<Simulation> simulation;

        double elapsedTime = 0.0; // seconds
        double previousTime = SimulationRunner::getCurrentSeconds();
        double timeScale = 1.0;
        double simulatedTime; // seconds

        bool logElapsedTime = true;

    protected:
        virtual void startSimulation();
        virtual void stopSimulation();
        virtual void resetSimulation();

        virtual void tickSimulation();

    public:
        virtual ~SimulationRunner() = default;

        static const double getCurrentSeconds();

        void setSimulation(std::unique_ptr<Simulation> simulation);
        std::unique_ptr<Simulation>& getSimulation();

        void setTimeScale(double scale);

        const double getElapsedTime();
        const double getTimeScale();
        const double getSimulatedTime();

        virtual void run() = 0;
};

#endif
