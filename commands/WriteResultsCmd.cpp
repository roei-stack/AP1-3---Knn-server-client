//
// Created by user on 9/25/2021.
//

#include "WriteResultsCmd.h"

WriteResultsCmd::WriteResultsCmd(IClassifier *classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

void WriteResultsCmd::execute() {
    vector<string>* results = this->classifier->getResults();

    int i = 1;
    for (const string& s : *results) {
        string toPrint = std::to_string(i) + "\t" + s;
        this->dio->write(toPrint);
        i++;
    }
    this->dio->write("Done.");
}

string WriteResultsCmd::description() {
    return this->cmdDescription;
}

