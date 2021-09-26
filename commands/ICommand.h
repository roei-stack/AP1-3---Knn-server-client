//
// Created by user on 9/24/2021.
//

#ifndef HW3_ICOMMAND_H
#define HW3_ICOMMAND_H

#include <string>
#include <vector>
#include <sstream>
#include "DefaultIO.h"
#include "DistCalcFactory.h"
#include "IClassifier.h"

using std::string;

class ICommand {
public:
    virtual void execute() = 0;
    virtual string description() = 0;
};


#endif //HW3_ICOMMAND_H
