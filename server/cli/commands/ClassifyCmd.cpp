//
// Created by user on 9/26/2021.
//

#include "ClassifyCmd.h"
ClassifyCmd::ClassifyCmd(IClassifier *classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

void ClassifyCmd::execute(string& menu) {
    try {
        this->classifier->classifyAllTestingData();
        this->dio->writeLine("classifying data complete\n" + menu);
    } catch (std::exception& e) {
        this->dio->writeLine(string(e.what()) + "\n" + menu);
    }
}

string ClassifyCmd::description() {
    return this->cmdDescription;
}

