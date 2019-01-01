#include <iostream>
#include <memory>

#include "boost/log/core.hpp"
#include "boost/log/trivial.hpp"
#include "boost/log/expressions.hpp"

#include "BasicSimulationRunner.h"
#include "Simulation.h"
#include "Ant.h"

#define LOG BOOST_LOG_TRIVIAL

void initLogging();
void runSim();

int main(int argc, const char** argv) {
    initLogging();

    runSim();
}

void initLogging() {
    // Set logging level
    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= boost::log::trivial::debug
    );
}

void runSim() {
    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>();

    sim->addColony(std::make_unique<Colony>("Ant Colony"));

    sim->getColonies().at(0)->addMember(std::make_unique<Ant>());

    LOG(info) << *sim;

    BasicSimulationRunner runner;

    runner.setSimulation(std::move(sim));

    runner.run();
}
