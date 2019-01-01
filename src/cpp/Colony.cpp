#include "Colony.h"

#define LOG BOOST_LOG_TRIVIAL

Colony::Colony() {
    this->name = "Generic Colony";
}

Colony::Colony(std::string name) {
    this->name = name;
}

void Colony::addMember(std::unique_ptr<Organism> member) {
    this->members.push_back(std::move(member));
}

template<class InputIter>
void Colony::addMembers(InputIter begin, InputIter end) {
    for (begin; begin != end; ++begin) {
        this->members.push_back(std::move(*begin));
    }
}

const std::vector<std::unique_ptr<Organism>>& Colony::getMembers() {
    return this->members;
}

void Colony::setName(std::string name) {
    this->name = name;
}

const std::string Colony::getName() {
    return this->name;
}

const int Colony::size() const {
    return this->members.size();
}

const int Colony::dead() const {
    int count = 0;

    for (auto memberIter = this->members.cbegin(); memberIter != this->members.cend(); ++memberIter) {
        if (!(*memberIter)->isAlive()) {
            ++count;
        }
    }

    return count;
}

void Colony::tick(double deltaSeconds) {
    for (auto memberIter = this->members.begin(); memberIter != this->members.end(); ++memberIter) {
        (*memberIter)->tick(deltaSeconds);
    }
}

void Colony::reset() {
    LOG(info) << "Colony '" << this->name << "' reset!";
}

std::ostream& operator<< (std::ostream& out, const Colony& colony) {
    out << "Colony: {Name: '" << colony.name << "', ";
    out << "No. Members: " << colony.size() << ", ";
    out << "No. Dead: " << colony.dead() << "}";

    return out;
}
