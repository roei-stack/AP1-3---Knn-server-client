//
// Created by user on 9/25/2021.
//

#include "UpdateSettingsCmd.h"

UpdateSettingsCmd::UpdateSettingsCmd(IClassifier *classifier, DefaultIO *io) {
    this->dio = io;
    this->classifier = classifier;
}


void UpdateSettingsCmd::execute() {
    string toWrite = "The current KNN parameters are: K = " + std::to_string(this->classifier->getK())
                     + ", distance metric = " + this->classifier->getMetricName();
    this->dio->write(toWrite);

    string response = this->dio->read();
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
            // kStr = 123hgkjglk is not valid, k must be between 1 to 10
            if (std::to_string(k) != kStr || !(k>=1 && k <=10)) {
                validK = false;
            }
        } catch (...) {
            validK = false;
        }

        // todo maybe change in classifier setDistanceCalculatingMethod to get a calc obj as param
        bool validMetric = true;
        if (validK) {
            try {
                this->classifier->setDistanceCalculatingMethod(metric);
            } catch (...) {
                //todo specify catch
                validMetric = false;
            }
        }

        if (validK && validMetric) {
            this->classifier->setK(k);

            this->dio->write("Updated successfully");
        } else if (!validK) {
            this->dio->write("Invalid K");
        } else if (!validMetric) {
            this->dio->write("Invalid Metric Name");
        }
    }
}

string UpdateSettingsCmd::description() {
    return this->cmdDescription;
}