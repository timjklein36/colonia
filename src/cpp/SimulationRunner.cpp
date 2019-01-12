#include "SimulationRunner.h"

const double SimulationRunner::getCurrentSeconds() {
    return boost::posix_time::microsec_clock::universal_time()
        .time_of_day()
        .total_microseconds()
        / 1e6;
}

void SimulationRunner::setSimulation(std::unique_ptr<Simulation> simulaiton) {
    this->simulation = std::move(simulaiton);
}

std::unique_ptr<Simulation>& SimulationRunner::getSimulation() {
    return this->simulation;
}

void SimulationRunner::setTimeScale(double scale) {
    this->timeScale = scale;
}

const double SimulationRunner::getElapsedTime() {
    return this->elapsedTime;
}

const double SimulationRunner::getTimeScale() {
    return this->timeScale;
}

const double SimulationRunner::getSimulatedTime() {
    return this->simulatedTime;
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

void SimulationRunner::tickSimulation() {
    double deltaSeconds = SimulationRunner::getCurrentSeconds() - this->previousTime;

    this->previousTime = deltaSeconds + this->previousTime;

    this->elapsedTime += deltaSeconds;

    double secondsToSimulate = deltaSeconds * this->timeScale;

    this->simulatedTime += secondsToSimulate;

    this->simulation->tick(secondsToSimulate);

    if ((int)this->elapsedTime % 2 == (int)this->logElapsedTime) {
        LOG(trace) << "Elapsed Time: [" << this->elapsedTime << "].";
        LOG(debug) << "Ant location: " << *this->simulation->getColonies().at(0)->getMembers().at(0);
        this->logElapsedTime = !this->logElapsedTime;
    }
}
