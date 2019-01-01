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

void Colony::tick(double deltaSeconds) {
    for (auto iter = this->members.begin(); iter != this->members.end(); ++iter) {
        (*iter)->tick(deltaSeconds);
    }
}

void Colony::reset() {
    LOG(info) << "Colony '" << this->name << "' reset!";
}

std::ostream& operator<< (std::ostream& out, const Colony& colony) {
    out << "Colony: {Name: '" << colony.name << "', ";
    out << "Members: [";

    for (auto iter = colony.members.cbegin(); iter != colony.members.cend(); ++iter) {
        if (iter != colony.members.cbegin()) {
            out << ", ";
        }

        out << **iter; // Input Organism pointed to by pointer (after dereference)
    }

    out << "]}";

    return out;
}
