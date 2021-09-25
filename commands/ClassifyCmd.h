//
// Created by user on 9/25/2021.
//

#ifndef HW3_CLASSIFYCMD_H
#define HW3_CLASSIFYCMD_H

#include "DefaultIO.h"
#include "IClassifier.h"
#include "ICommand.h"


class ClassifyCmd : public ICommand {
private:
    string cmdDescription = "display results";
    IClassifier* classifier;
    DefaultIO* dio;

public:
    void execute() override;
};


#endif //HW3_CLASSIFYCMD_H
