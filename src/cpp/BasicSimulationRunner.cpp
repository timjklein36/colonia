#include "BasicSimulationRunner.h"

BasicSimulationRunner::BasicSimulationRunner(): quit(false) {}

void BasicSimulationRunner::run() {
    this->startSimulation();

    while (!this->quit) {
        this->tick();

        if (this->pollForInput()) {
            bool isValidInput = false;

            while (!isValidInput) {
                std::cout << "What would you like to do? (Type '?' for available commands): ";
                std::getline(std::cin, this->input);

                boost::trim(this->input); // Trim leading and trailing whitespace

                isValidInput = this->validateInput();
            }

            this->executeInputCommand();
        }
    }
}

bool BasicSimulationRunner::pollForInput() {
    if (this->isInterrupted()) {
        LOG(info) << "Interrupt detected!";

        return true;
    } else {
        return false;
    }
}

bool BasicSimulationRunner::validateInput() {
    LOG(debug) << "User input command: '" << this->input << "'";
    return this->input == "q";
}

bool BasicSimulationRunner::isInterrupted() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::X)
        && (
            sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)
        );
}

void BasicSimulationRunner::executeInputCommand() {
    this->quitRunner();
}

void BasicSimulationRunner::quitRunner() {
    LOG(info) << "Simulation Runner quit: stopping Simulation.";
    this->stopSimulation();
    this->quit = true;
}
