//
// Created by user on 9/25/2021.
//

#include "WriteResultsCmd.h"

WriteResultsCmd::WriteResultsCmd(IClassifier *classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

void WriteResultsCmd::execute() {
    try {
        this->dio->writeLine(this->output().str());
    } catch (std::exception& e) {
        this->dio->writeLine(e.what());
    }
}

string WriteResultsCmd::description() {
    return this->cmdDescription;
}

std::stringstream WriteResultsCmd::output() {
    vector<string> results;
    results = this->classifier->getResults();
    std::stringstream content;
    int i = 1;
    for (const string& s : results) {
        content << std::to_string(i) + "\t" + s << std::endl;
        i++;
    }
    content << "Done.";
    return content;
}

