#ifndef BASIC_SIMULATION_RUNNER_H
#define BASIC_SIMULATION_RUNNER_H

#include <string>
#include <iostream>
#include <set>

#include "boost/algorithm/string.hpp"
#include "boost/algorithm/cxx11/any_of.hpp"

#include "SFML/Window.hpp"

#include "SimulationRunner.h"

class BasicSimulationRunner: public SimulationRunner {
    private:
        bool quit;

        std::string input;

        std::set<std::string> validInputCommands = {"p", "q", "r", "s", "x"};

        void quitRunner();

        bool pollForInput();
        bool validateInput();

        bool isInterrupted();

        void executeInputCommand();

    public:
        BasicSimulationRunner();

        void run();
};

#endif
