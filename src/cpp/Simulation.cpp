#include "Simulation.h"

Simulation::Simulation() {}

Simulation::Simulation(Simulation&& simulation) {
    this->colonies = std::move(simulation.colonies);
}

void Simulation::addColony(std::unique_ptr<Colony> colony) {
    this->colonies.push_back(std::move(colony));
}

const std::vector<std::unique_ptr<Colony>>& Simulation::getColonies() {
    return this->colonies;
}

void Simulation::start() {}

void Simulation::stop() {}

void Simulation::reset() {
    for (auto iter = this->colonies.begin(); iter != this->colonies.end(); ++iter) {
        (*iter)->reset();
    }
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
