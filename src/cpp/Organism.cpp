#include <ostream>

#include "Organism.h"

std::ostream& operator<< (std::ostream& out, const Organism& organism) {
    out << organism.living;
    return out;
}