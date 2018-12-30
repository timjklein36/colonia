#include <iostream>

#include "boost/log/trivial.hpp"

#include "Simulation.h"

#define LOG BOOST_LOG_TRIVIAL

int main(int argc, const char** argv) {
    Simulation sim;

    Colony antColony("Ant Colony");

    sim.addColony(antColony);

    LOG(info) << sim;

    sim.reset();
}
