#include "SimulationRunner.h"

void SimulationRunner::setSimulation(std::unique_ptr<Simulation> simulaiton) {
    this->simulation = std::move(simulaiton);
}

std::unique_ptr<Simulation>& SimulationRunner::getSimulation() {
    return this->simulation;
}

void SimulationRunner::startSimulation() {
    this->simulation->start();
}

void SimulationRunner::stopSimulation() {
    this->simulation->stop();
}

void SimulationRunner::resetSimulation() {
    this->simulation->reset();
}

void SimulationRunner::tick() {
    if (this->simulation->isRunning()) {
        this->simulation->tick();
    }
}
