//
// Created by user on 9/24/2021.
//

#ifndef HW3_UPLOADCMD_H
#define HW3_UPLOADCMD_H

#include "ICommand.h"
#include "LineToClassifiableConverter.h"


class UploadCmd : public ICommand {
private:
    string cmdDescription = "upload an unclassified csv data file";
    IClassifier* classifier;
    DefaultIO* dio;

    std::vector<Classifiable*>* receiveDataset();

public:
    UploadCmd(IClassifier* classifier, DefaultIO* io);

    std::string description() override;

    void execute() override;
};


#endif //HW3_UPLOADCMD_H
