#ifndef ORGANISM_H
#define ORGANISM_H

#include <ostream>

#include "boost/geometry.hpp"
#include "boost/geometry/geometries/point_xy.hpp"

typedef boost::geometry::model::d2::point_xy<double> Point;

class Organism {
    private:
        bool alive;
        unsigned short energy;

    protected:
        Organism();

        bool aboveGround;

        /*
         * If the Animal is above ground then the underGroundLocation has no relevance
         * and vice versa.
         */

        Point aboveGroundLocation; // Location on the flat x-y ground plane
        Point underGroundLocation; // Location on flat, x-y in-ground cross-section

        void setAlive(bool alive);

        void setEnergy(unsigned short energy);

    public:
        virtual ~Organism() = default;

        const bool isAlive();

        const unsigned short getEnergy();

        virtual const unsigned short getMaxEnergy() = 0;

        void setAboveGround(bool aboveGround);
        const bool isAboveGround();

        void setAboveGroundLocation(Point loc);
        const Point getAboveGroundLocation();

        void setUnderGroundLocation(Point loc);
        const Point getUnderGroundLocation();

        virtual void tick(double deltaSeconds) = 0;

        friend std::ostream& operator<< (std::ostream& out, const Organism& organism);
};

#endif