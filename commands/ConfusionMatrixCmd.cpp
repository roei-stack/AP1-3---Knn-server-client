//
// Created by user on 9/26/2021.
//

#include "ConfusionMatrixCmd.h"

ConfusionMatrixCmd::ConfusionMatrixCmd(IClassifier *classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

void ConfusionMatrixCmd::execute() {
    auto mat = this->classifier->calculateConfusionMatrix();
    // PRINTING THE CONFUSION MATRIX
    // TOP LINE
    std::stringstream ssMat;
    ssMat << "\t";
    for (auto &className : mat) {
        ssMat << "\t" << className.first;
    }
    ssMat << std::endl;
    // REST OF THE MATRIX
    for (auto& i : mat) {
        ssMat << i.first;
        for (double x : i.second) {
            ssMat << "\t" << x << "%";
        }
        ssMat << std::endl;
    }

    string sMat;
    ssMat >> sMat;

    this->dio->write(sMat);
}

string ConfusionMatrixCmd::description() {
    return this->cmdDescription;
}


