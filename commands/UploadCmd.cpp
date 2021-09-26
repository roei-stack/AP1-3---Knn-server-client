//
// Created by user on 9/24/2021.
//

#include "UploadCmd.h"
#include "LineToClassifiableConverter.h"

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
    auto* train = receiveDataset();
    this->classifier->setTrainingData(train);
    this->dio->write("Upload complete.");
    //uploading test
    this->dio->write("Please upload your local test csv file.");
    auto* test = receiveDataset();
    this->classifier->setTestingData(test);
    this->dio->write("Upload complete.");
}

std::vector<Classifiable *> *UploadCmd::receiveDataset() {
    auto* data = new vector<Classifiable*>;
    //todo should be readLine
    string line = this->dio->read();
    while (line != "Done.") {
        Classifiable* c = LineToClassifiableConverter::convert(line);
        data->push_back(c);
        //todo should be readLine
        line = this->dio->read();
    }
    return data;
}


