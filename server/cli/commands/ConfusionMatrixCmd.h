//
// Created by user on 9/26/2021.
//

#ifndef HW3_CONFUSIONMATRIXCMD_H
#define HW3_CONFUSIONMATRIXCMD_H

#include "ICommand.h"

class ConfusionMatrixCmd : public ICommand {
private:
    string cmdDescription = "display algorithm confusion matrix";
    IClassifier* classifier;
    DefaultIO* dio;

public:
    ConfusionMatrixCmd(IClassifier *classifier, DefaultIO *io);
    void execute() override;
    string description() override;
};


#endif //HW3_CONFUSIONMATRIXCMD_H
