#ifndef COLONY_H
#define COLONY_H

#include <vector>
#include <iterator>
#include <string>
#include <memory>

#include "boost/log/trivial.hpp"

#include "Organism.h"

class Colony {
    private:
        std::vector<std::unique_ptr<Organism>> members;
        std::string name;

    public:
        Colony();
        Colony(std::string name);

        void addMember(std::unique_ptr<Organism> member);
        template<class InputIter> void addMembers(InputIter begin, InputIter end);
        const std::vector<std::unique_ptr<Organism>>& getMembers();

        void setName(std::string name);
        const std::string getName();

        const int size() const;
        const int dead() const;

        void tick(double deltaSeconds);

        void reset();

        friend std::ostream& operator<< (std::ostream& out, const Colony& colony);
};

#endif
