//
// Created by user on 9/24/2021.
//

#include "UploadCmd.h"

UploadCmd::UploadCmd(IClassifier* classifier, DefaultIO *io) {
    this->classifier = classifier;
    this->dio = io;
}

std::string UploadCmd::description() {
    return this->cmdDescription;
}

void UploadCmd::execute() {
    //uploading train
    this->dio->write("Please upload your local train csv file.");


    //uploading test
}


