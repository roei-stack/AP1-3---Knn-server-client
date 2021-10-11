//
// Created by user on 9/26/2021.
//

#include "ClassifyCmd.h"
ClassifyCmd::ClassifyCmd(IClassifier *classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

void ClassifyCmd::execute() {
    try {
        this->classifier->classifyAllTestingData();
        this->dio->write("classifying data complete");
    } catch (std::exception& e) {
        this->dio->write(e.what());
    }
}

string ClassifyCmd::description() {
    return this->cmdDescription;
}

