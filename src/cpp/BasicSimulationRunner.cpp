#include "BasicSimulationRunner.h"

BasicSimulationRunner::BasicSimulationRunner(): quit(false) {}

void BasicSimulationRunner::run() {
    this->startSimulation();

    while (!this->quit) {
        this->tickSimulation();

        if (this->pollForInput()) {
            bool isValidInput = false;

            while (!isValidInput) {
                std::cout << "What would you like to do? (Type '?' for available commands): ";

                std::getline(std::cin, this->input);

                boost::trim(this->input); // Trim leading and trailing whitespace

                std::vector<std::string> splitInput;

                boost::split(splitInput, this->input, boost::is_any_of(" ")); // Split on space

                this->input = splitInput.at(0);

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

    if (this->input == "?") {
        std::cout << "Available commands:" << std::endl;
        std::cout << "    p    - pause simulation" << std::endl
                  << "    s    - start simulation" << std::endl
                  << "    r    - reset simulation" << std::endl
                  << "    q    - quit program" << std::endl
                  << "    x    - resume execution" << std::endl;
    }

    return boost::algorithm::any_of_equal(this->validInputCommands, this->input);
}

bool BasicSimulationRunner::isInterrupted() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::X)
        && (
            sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)
        );
}

void BasicSimulationRunner::executeInputCommand() {
    if (this->input == "q") {
        this->quitRunner();
    } else if (this->input == "p") {
        this->stopSimulation();
    } else if (this->input == "r") {
        this->resetSimulation();
    } else if (this->input == "s") {
        this->startSimulation();
    }
}

void BasicSimulationRunner::quitRunner() {
    LOG(info) << "Simulation Runner quit: stopping Simulation.";
    this->stopSimulation();
    this->quit = true;
}
