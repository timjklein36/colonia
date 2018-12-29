#include <iostream>

#include "boost/log/trivial.hpp"

#include "Colony.h"

#define LOG BOOST_LOG_TRIVIAL

int main(int argc, const char** argv) {
    Colony antColony("My Ant Colony");

    LOG(info) << antColony;
}
