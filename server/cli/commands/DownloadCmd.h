#ifndef TESTCLASSIFIER_CPP_DOWNLOADCMD_H
#define TESTCLASSIFIER_CPP_DOWNLOADCMD_H

#include "ICommand.h"
#include "WriteResultsCmd.h"

class DownloadCmd : public ICommand {
private:

    string cmdDescription = "download results";
    IClassifier* classifier;
    DefaultIO* dio;
public:
    DownloadCmd(IClassifier* classifier, DefaultIO *io);
    void execute(string& menu) override;
    string description() override;
};


#endif //TESTCLASSIFIER_CPP_DOWNLOADCMD_H
