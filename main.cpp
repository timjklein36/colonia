#include <iostream>
#include <memory>

#include "boost/log/trivial.hpp"

#include "Simulation.h"
#include "Ant.h"

#define LOG BOOST_LOG_TRIVIAL

int main(int argc, const char** argv) {
    Simulation sim;

    sim.addColony(std::make_unique<Colony>("Ant Colony"));

    LOG(info) << sim;

    sim.getColonies()[0]->addMember(std::make_unique<Ant>());

    LOG(info) << sim;
}
