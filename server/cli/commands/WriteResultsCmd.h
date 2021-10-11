//
// Created by user on 9/25/2021.
//

#ifndef HW3_WRITERESULTSCMD_H
#define HW3_WRITERESULTSCMD_H

#include "ICommand.h"

using std::vector;

/**
 * commands 4 & 5
 */
class WriteResultsCmd : public ICommand {
private:
    string cmdDescription = "display results";
    IClassifier* classifier;
    DefaultIO* dio;

public:
    WriteResultsCmd(IClassifier *classifier, DefaultIO *io);
    void execute() override;
    string description() override;
};


#endif //HW3_WRITERESULTSCMD_H
