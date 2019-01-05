#include "Simulation.h"

void Simulation::addColony(std::unique_ptr<Colony> colony) {
    this->colonies.push_back(std::move(colony));
}

const std::vector<std::unique_ptr<Colony>>& Simulation::getColonies() {
    return this->colonies;
}

void Simulation::start() {
    if (this->running) {
        LOG(warning) << "Simulation is already running.";
    } else {
        LOG(info) << "Simulation started.";
        this->running = true;
    }
}

void Simulation::stop() {
    if (!this->running) {
        LOG(warning) << "Simulation is already stopped.";
    } else {
        LOG(info) << "Simulation stopped.";
        this->running = false;
    }
}

void Simulation::reset() {
    LOG(info) << "Simulation beginning reset...";

    this->stop();

    for (auto iter = this->colonies.begin(); iter != this->colonies.end(); ++iter) {
        (*iter)->reset();
    }

    LOG(info) << "Simulation reset complete.";
}

void Simulation::tick(double deltaSeconds) {
    if (this->running) {
        LOG(trace) << "Simulation ticked. (Simulated) Delta Seconds: [" << deltaSeconds << "].";

        for (auto colonyIter = this->colonies.begin(); colonyIter != this->colonies.end(); ++colonyIter) {
            (*colonyIter)->tick(deltaSeconds);
        }
    } else {
        // Do nothing, as simulation is stopped (possible idle processing could go here)
    }
}

bool Simulation::isRunning() {
    return this->running;
}

std::ostream& operator<< (std::ostream& out, const Simulation& sim) {
    out << "Simulation: {Colonies: [";

    for (auto iter = sim.colonies.cbegin(); iter != sim.colonies.cend(); ++iter) {
        if (iter != sim.colonies.cbegin()) {
            out << ", ";
        }

        out << **iter;
    }

    out << "]}";

    return out;
}
