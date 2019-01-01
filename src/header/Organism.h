#ifndef ORGANISM_H
#define ORGANISM_H

#include <ostream>

class Organism {
    private:
        bool alive;
        unsigned short energy;

    protected:
        void setAlive(bool alive);

        void setEnergy(unsigned short energy);

    public:
        virtual ~Organism() = default;

        const bool isAlive();

        const unsigned short getEnergy();

        virtual const unsigned short getMaxEnergy() = 0;

        virtual void tick(double deltaSeconds) = 0;

        friend std::ostream& operator<< (std::ostream& out, const Organism& organism);
};

#endif