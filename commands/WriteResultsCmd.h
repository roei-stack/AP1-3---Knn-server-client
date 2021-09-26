//
// Created by user on 9/25/2021.
//

#ifndef HW3_WRITERESULTSCMD_H
#define HW3_WRITERESULTSCMD_H

#include "ICommand.h"

using std::vector;

class WriteResultsCmd : public ICommand {
private:
    string cmdDescription = "display results";
    IClassifier* classifier;
    DefaultIO* dio;

public:
    void execute() override;
};


#endif //HW3_WRITERESULTSCMD_H
