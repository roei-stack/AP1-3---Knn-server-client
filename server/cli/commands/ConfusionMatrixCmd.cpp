#include "ConfusionMatrixCmd.h"

ConfusionMatrixCmd::ConfusionMatrixCmd(IClassifier *classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

void ConfusionMatrixCmd::execute(string& menu) {
    vector<std::pair<string, vector<double>>> mat;
    try {
        mat = this->classifier->calculateConfusionMatrix();
    }
    catch (std::exception& e) {
        this->dio->writeLine(string(e.what()) + "\n" + menu);
        return;
    }
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
    ssMat << std::endl << menu;

    string sMat = ssMat.str();
    this->dio->writeLine(sMat);
}

string ConfusionMatrixCmd::description() {
    return this->cmdDescription;
}


