#include "DownloadCmd.h"

DownloadCmd::DownloadCmd(IClassifier *classifier, DefaultIO *io) {
    this->dio = io;
    this->classifier = classifier;
}

void DownloadCmd::execute(string& menu) {
    WriteResultsCmd cmd(this->classifier, this->dio);
    std::stringstream ss;
    try {
        ss << "save" << std::endl << cmd.output().str();
        this->dio->writeLine(ss.str() + "\n" + menu);
    } catch (std::exception& e) {
        this->dio->writeLine(string(e.what()) + "\n" + menu);
    }
}

string DownloadCmd::description() {
    return this->cmdDescription;
}