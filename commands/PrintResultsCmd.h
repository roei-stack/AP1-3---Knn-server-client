//
// Created by user on 9/25/2021.
//

#ifndef HW3_PRINTRESULTSCMD_H
#define HW3_PRINTRESULTSCMD_H

#include <vector>
using std::vector;
#include "IClassifier.h"
#include "ICommand.h"

class PrintResultsCmd : public ICommand {
private:
    string cmdDescription = "display results";
    IClassifier* classifier;

public:
    void execute() override;
};


#endif //HW3_PRINTRESULTSCMD_H
