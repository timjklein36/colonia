#ifndef COLONY_H
#define COLONY_H

#include <vector>
#include <iterator>
#include <string>

#include "Organism.h"

class Colony {
    private:
        std::vector<Organism> members;
        std::string name;

    public:
        Colony();
        Colony(std::string name);

        void addMember(Organism& member);
        template<class InputIter> void addMembers(InputIter begin, InputIter end);
        const std::vector<Organism> getMembers();

        void setName(std::string name);
        const std::string getName();

        const int size();
        const int dead();

        friend std::ostream& operator<< (std::ostream& out, const Colony& colony);
};

#endif
