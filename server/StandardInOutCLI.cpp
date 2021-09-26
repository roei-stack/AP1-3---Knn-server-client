//
// Created by user on 9/26/2021.
//

#include "StandardInOutCLI.h"

void StandardInOutCLI::start() {
    writeMenu();
    string in;
    std::cin >> in;
    int option = std::stoi(in);
    while (option != this->commands.size()) {
        ICommand* toExecute = this->commands[option];
        toExecute->execute();
    }
}

void StandardInOutCLI::writeMenu() {
    this->io->write("Welcome to the Knn Classifier CLI. Please choose an option:");
    int i = 1;
    for (ICommand* command : this->commands) {
        string toWrite = std::to_string(i) + ".\t" + command->description();
        this->io->write(toWrite);
        i++;
    }
    string toWrite = std::to_string(i) + ".\texit";
}
