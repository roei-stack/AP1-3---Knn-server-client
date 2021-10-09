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
    vector<Classifiable*>* train;
    try {
        train = receiveDataset();
    } catch (std::exception& e) {
        this->dio->write(e.what());
        return;
    }
    this->classifier->setTrainingData(train);
    this->dio->write("Upload complete.\n\rPlease upload your local test csv file.");
    vector<Classifiable*>* test;
    try {
        test = receiveDataset();
    } catch (std::exception& e) {
        this->dio->write(e.what());
        return;
    }
    this->classifier->setTestingData(test);
    this->dio->write("Upload complete.");
}

std::vector<Classifiable *> *UploadCmd::receiveDataset() {
    auto* data = new vector<Classifiable*>;
    int counter = 0;
    // reading entire file at once
    string content = this->dio->read();
    std::replace(content.begin(), content.end(), ':', ' ');
    std::stringstream ss(content);
    string line;
    while (ss >> line) {
        if (line == "Done.") {
            break;
        }
        Classifiable* c = LineToClassifiableConverter::convert(line, counter);
        data->push_back(c);
        counter++;
    }
    return data;
}


