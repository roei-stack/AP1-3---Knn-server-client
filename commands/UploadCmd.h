//
// Created by user on 9/24/2021.
//

#ifndef HW3_UPLOADCMD_H
#define HW3_UPLOADCMD_H

#include "ICommand.h"
#include "Classifier.h"

class UploadCmd : public ICommand {
private:
    //todo Classifier<?>* classifier;
    //todo DefaultIO* dio;

public:
    //todo
    UploadCmd(){

    }

    std::string description() override;

    void execute() override;
};


#endif //HW3_UPLOADCMD_H