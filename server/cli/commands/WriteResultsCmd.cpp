//
// Created by user on 9/25/2021.
//

#include "WriteResultsCmd.h"

WriteResultsCmd::WriteResultsCmd(IClassifier *classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

void WriteResultsCmd::execute(string& menu) {
    try {
        this->dio->writeLine(this->output().str() + "\n" + menu);
    } catch (std::exception& e) {
        this->dio->writeLine(string(e.what()) + "\n" + menu);
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

