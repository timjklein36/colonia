#ifndef ORGANISM_H
#define ORGANISM_H

#include <ostream>

class Organism {
    private:
        bool living;

    protected:
        explicit Organism();

    public:
        Organism(const Organism&) = delete;
        Organism& operator= (const Organism&) = delete;

        ~Organism() = default;

        const bool isAlive();

        friend std::ostream& operator<< (std::ostream& out, const Organism& organism);
};

#endif