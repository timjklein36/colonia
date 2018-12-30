#include "Simulation.h"

#include <algorithm>

Simulation::Simulation() {}

void Simulation::addColony(Colony& colony) {
    this->colonies.push_back(colony);
}

const std::vector<Colony> Simulation::getColonies() {
    return this->colonies;
}

void Simulation::start() {}

void Simulation::stop() {}

void Simulation::reset() {
    std::for_each(this->colonies.begin(), this->colonies.end(), [](Colony& c) {
        c.reset();
    });
}

std::ostream& operator<< (std::ostream& out, const Simulation& sim) {
    out << "Simulation: {Colonies: [";

    for (auto iter = sim.colonies.cbegin(); iter != sim.colonies.cend(); ++iter) {
        if (iter != sim.colonies.cbegin()) {
            out << ", ";
        }

        out << *iter;
    }

    out << "]}";

    return out;
}
