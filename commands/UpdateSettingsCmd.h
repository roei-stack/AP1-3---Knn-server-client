//
// Created by user on 9/25/2021.
//

#ifndef HW3_UPDATESETTINGSCMD_H
#define HW3_UPDATESETTINGSCMD_H

#include "ICommand.h"

class UpdateSettingsCmd : public ICommand {
private:
    string cmdDescription = "algorithm settings";
    IClassifier* classifier;
    DefaultIO* dio;

public:
    void execute() override;
};


#endif //HW3_UPDATESETTINGSCMD_H
