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
#include "ConfusionMatrixCmd.h"
#include "WriteResultsCmd.h"
#include "UpdateSettingsCmd.h"
#include "ClassifyCmd.h"

using std::vector;

class CLI {
private:
    KnnClassifier* classifier = new KnnClassifier;
    DefaultIO* io;
    vector<ICommand*> commands;
    void writeMenu();

public:
    explicit CLI(DefaultIO* io);
    void start();

    // todo destructor
};


#endif //HW3_STANDARDINOUTCLI_H
