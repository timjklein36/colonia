#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>
#include <string>

enum Direction {
    POS_X,
    POS_Y,
    NEG_X,
    NEG_Y
};

namespace direction {
    inline std::string directionToString(const Direction& dir) {
        switch(dir) {
            case POS_X:
                return "POSITIVE-X";
            case POS_Y:
                return "POSITIVE-Y";
            case NEG_X:
                return "NEGATIVE-X";
            case NEG_Y:
                return "NEGATIVE-Y";
            default:
                return "UNKONWN-DIRECTION";
        }
    }

    inline std::ostream & operator << (std::ostream& out, const Direction& dir) {
        out << directionToString(dir);
        return out;
    }
};

#endif
