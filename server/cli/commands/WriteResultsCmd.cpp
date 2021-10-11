//
// Created by user on 9/25/2021.
//

#include "WriteResultsCmd.h"

WriteResultsCmd::WriteResultsCmd(IClassifier *classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

void WriteResultsCmd::execute() {
    vector<string> *results;
    try {
         results = this->classifier->getResults();
    } catch (std::exception& e) {
        this->dio->write(e.what());
        return;
    }
    std::stringstream content;
    int i = 1;
    for (const string& s : *results) {
        content << std::to_string(i) + "\t" + s << std::endl;
        i++;
    }
    content << "Done.";
    this->dio->write(content.str());
}

string WriteResultsCmd::description() {
    return this->cmdDescription;
}

