#include "CLI.h"

CLI::CLI(DefaultIO *io) {
    this->io = io;
    this->commands.push_back(new UploadCmd(classifier, io));
    this->commands.push_back(new UpdateSettingsCmd(classifier, io));
    this->commands.push_back(new ClassifyCmd(classifier, io));
    this->commands.push_back(new WriteResultsCmd(classifier, io));
    // downloadCmd
    this->commands.push_back(new ConfusionMatrixCmd(classifier, io));

}

void CLI::start() {
    writeMenu();
    string in;
    in = this->io->read();
    int option = std::stoi(in);
    while (option != this->commands.size()) {
        ICommand* toExecute = this->commands[option - 1];
        toExecute->execute();
    }
}

void CLI::writeMenu() {
    this->io->write("Welcome to the Knn Classifier CLI. Please choose an option:");
    int i = 1;
    for (ICommand* command : this->commands) {
        string toWrite = std::to_string(i) + ".\t" + command->description();
        this->io->write(toWrite);
        i++;
    }
    string toWrite = std::to_string(i) + ".\texit";
    this->io->write(toWrite);
}
