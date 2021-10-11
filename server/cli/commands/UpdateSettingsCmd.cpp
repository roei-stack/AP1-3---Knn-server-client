#include "UpdateSettingsCmd.h"

UpdateSettingsCmd::UpdateSettingsCmd(IClassifier *classifier, DefaultIO *io) {
    this->dio = io;
    this->classifier = classifier;
}

void UpdateSettingsCmd::execute(string& menu) {
    string toWrite = "The current KNN parameters are: K = " + std::to_string(this->classifier->getK())
                     + ", distance metric = " + this->classifier->getMetricName();
    std::stringstream out;
    this->dio->writeLine(toWrite);
    string response = this->dio->read();
    response = rtrim(response);
    if (!(response.empty())) {
        // we will split the response using the ' ' (space) character as a separator
        // the first token should be K and the second should be the metric name
        int k;
        string kStr, metric;
        char separator = ' ';
        size_t pos = response.find_first_of(separator);
        kStr = response.substr(0, pos);
        metric = response.substr(pos + 1);

        bool validK = true;
        try {
            k = std::stoi(kStr);
            // kStr = 5hgkjglk is not valid, k must be between 1 to 10
            if (std::to_string(k) != kStr || !(k>=1 && k <=10)) {
                validK = false;
            }
        } catch (...) {
            validK = false;
        }
        bool validMetric = true;
        if (validK) {
            try {
                this->classifier->setDistanceCalculatingMethod(metric);
            } catch (...) {
                validMetric = false;
            }
        }

        if (validK && validMetric) {
            this->classifier->setK(k);

            out << "Updated successfully";
        } else if (!validK) {
            out << "Invalid K";
        } else if (!validMetric) {
            out << "Invalid Metric Name";
        }
    }
    out << std::endl << menu;
    this->dio->writeLine(out.str());
}

string UpdateSettingsCmd::description() {
    return this->cmdDescription;
}

// remove all whitespaces from the right
std::string &UpdateSettingsCmd::rtrim(string &s) {
    auto it = std::find_if(s.rbegin(), s.rend(), [](char c) {
        return !std::isspace<char>(c, std::locale::classic());});
    s.erase(it.base(), s.end());
    return s;
}
