#ifndef UTIL_H
#define UTIL_H

#include <string>

class Util {
    public:
        template<typename T> static const std::string toString(const T& container);
};

#endif