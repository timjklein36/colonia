#ifndef ANT_H
#define ANT_H

#include "boost/log/trivial.hpp"

#include "Insect.h"

#define LOG BOOST_LOG_TRIVIAL

class Ant: public Insect {
    public:
        Ant();

        const unsigned short getMaxEnergy();

        void tick(double deltaSeconds);
};

#endif
