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
    std::string& rtrim(std::string &s);
public:
    UpdateSettingsCmd(IClassifier* classifier, DefaultIO *io);
    void execute() override;
    string description() override;
};


#endif //HW3_UPDATESETTINGSCMD_H
