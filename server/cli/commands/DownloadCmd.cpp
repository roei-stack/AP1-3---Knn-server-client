#include "DownloadCmd.h"

DownloadCmd::DownloadCmd(IClassifier *classifier, DefaultIO *io) {
    this->dio = io;
    this->classifier = classifier;
}

void DownloadCmd::execute() {
    WriteResultsCmd cmd(this->classifier, this->dio);
    std::stringstream ss;
    try {
        ss << "save" << std::endl << cmd.output().str();
        this->dio->writeLine(ss.str());
    } catch (std::exception& e) {
        this->dio->writeLine(e.what());
    }
}

string DownloadCmd::description() {
    return this->cmdDescription;
}