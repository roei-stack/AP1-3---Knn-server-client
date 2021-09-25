//
// Created by user on 9/25/2021.
//

#include "PrintResultsCmd.h"

void PrintResultsCmd::execute() {
    vector<string>* results = this->classifier->getResults();

    int i = 1;
    for (const string& s : *results) {
        string toPrint = std::to_string(i) + "\t" + s;
        std::cout << toPrint << std::endl;
        i++;
    }
    std::cout << "Done." << std::endl;
}
