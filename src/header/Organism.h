#ifndef ORGANISM_H
#define ORGANISM_H

class Organism {
    private:
        bool living;

        Organism();

    public:
        const bool isAlive();

        friend std::ostream& operator<< (std::ostream& out, const Organism& organism);
};

#endif