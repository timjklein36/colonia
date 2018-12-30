#include "Organism.h"

Organism::Organism() {}

std::ostream& operator<< (std::ostream& out, const Organism& organism) {
    out << organism.living;
    return out;
}