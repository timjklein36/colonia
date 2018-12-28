#include "Colony.h"

Colony::Colony() {
    this->name = "Generic Colony";
}

Colony::Colony(std::string name) {
    this->name = name;
}

void Colony::addMember(Organism& member) {
    this->members.push_back(member);
}

template<class InputIter>
void Colony::addMembers(InputIter begin, InputIter end) {
    for (begin; begin != end; ++begin) {
        this->members.push_back(*begin);
    }
}

const std::vector<Organism> Colony::getMembers() {
    return this->members;
}

void Colony::setName(std::string name) {
    this->name = name;
}

const std::string Colony::getName() {
    return this->name;
}

std::ostream& operator<< (std::ostream& out, const Colony& colony) {
    out << "Colony: '" << colony.name << "'" << std::endl;
    
    out << "Members: [";

    for (auto iter = colony.members.cbegin(); iter != colony.members.cend(); ++iter) {
        if (iter != colony.members.cbegin()) {
            out << ", ";
        }

        out << *iter;
    }

    out << "]";

    return out;
}
