//
// Created by user on 9/26/2021.
//

#ifndef HW3_STANDARDINOUTCLI_H
#define HW3_STANDARDINOUTCLI_H

#include "KnnClassifier.h"
#include "StandardIO.h"
#include "ICommand.h"
#include "UploadCmd.h"
#include <vector>
using std::vector;


class StandardInOutCLI {
private:
    KnnClassifier* classifier;
    StandardIO* io;
    vector<ICommand*> commands;

    void writeMenu();

public:
    StandardInOutCLI() {
        //todo this->classifier = new KnnClassifier();
        this->io = new StandardIO();
        //todo this->commands.push_back(new UploadCmd(classifier, io));
        //todo push_back the rest commands
    }

    void start();
};


#endif //HW3_STANDARDINOUTCLI_H
