//
// Created by user on 9/25/2021.
//

#include "WriteResultsCmd.h"

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
