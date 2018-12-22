#ifndef COLONY_H
#define COLONY_H

#include <vector>

#include "Organism.h"

class Colony {
    private:
        std::vector<Organism> members;

    public:
        Colony();

        void addMember(Organism& member);
        const std::vector<Organism> getMembers();

        const int size();
        const int dead();
};

#endif
