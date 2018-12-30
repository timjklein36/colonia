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
        explicit Colony();
        explicit Colony(std::string name);

        Colony(const Colony&) = delete;
        Colony& operator= (const Colony&) = delete;

        Colony(Colony&&) = default;

        ~Colony() = default;

        void addMember(std::unique_ptr<Organism> member);
        template<class InputIter> void addMembers(InputIter begin, InputIter end);
        const std::vector<std::unique_ptr<Organism>>& getMembers();

        void setName(std::string name);
        const std::string getName();

        const int size();
        const int dead();

        void reset();

        friend std::ostream& operator<< (std::ostream& out, const Colony& colony);
};

#endif
