#include "Util.h"

#include <sstream>
#include <string>

template<typename T>
const std::string Util::toString(const T& container) {
    std::ostringstream stream;

    for (auto iter = container.cbegin(); iter != container.cend(); ++iter) {
        stream << *iter;
        if (iter != --container.cend()) {
            stream << ", ";
        }
    }

    return stream.str();
}