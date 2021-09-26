//
// Created by user on 9/26/2021.
//

#ifndef HW3_CONFUSIONMATRIXCMD_H
#define HW3_CONFUSIONMATRIXCMD_H

#include <DefaultIO.h>
#include "ICommand.h"

class ConfusionMatrixCmd : public ICommand {
private:
    string cmdDescription = "display algorithm confusion matrix";
    IClassifier* classifier;
    DefaultIO* dio;

public:
    void execute() override;
};


#endif //HW3_CONFUSIONMATRIXCMD_H
