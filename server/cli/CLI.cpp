#include "CLI.h"

CLI::CLI(DefaultIO *io) {
    this->io = io;
    this->commands.push_back(new UploadCmd(classifier, io));
    this->commands.push_back(new UpdateSettingsCmd(classifier, io));
    this->commands.push_back(new ClassifyCmd(classifier, io));
    this->commands.push_back(new WriteResultsCmd(classifier, io));
    // TODO downloadCmd (for the server it is same as the WriteResultsCmd, the client code need to write to a file)
    this->commands.push_back(new ConfusionMatrixCmd(classifier, io));
}

void CLI::start() {
    this->writeMenu();
    while (true) {
        string in = this->io->read();
        int option;
        try {
            option = std::stoi(in);
            if (option < 1 || option > this->commands.size() + 1) {
                throw 0; // todo why try catch and not just if
            }
        } catch (...) {
            this->io->writeLine("Invalid command!");
            continue;
        }
        if (option == this->commands.size() + 1) {
            this->io->writeLine("exit");
            // todo clear resources
            break;
        }
        ICommand* toExecute = this->commands[option - 1];
        toExecute->execute();
    }
}

void CLI::writeMenu() {
    std::stringstream stream;
    stream << "Welcome to the Knn Classifier CLI. Please choose an option:" << std::endl;
    int i = 1;
    for (ICommand* command : this->commands) {
        stream << std::to_string(i) + ".\t" + command->description() << std::endl;
        i++;
    }
    stream << std::to_string(i) + ".\texit";
    this->io->writeLine(stream.str());
}

