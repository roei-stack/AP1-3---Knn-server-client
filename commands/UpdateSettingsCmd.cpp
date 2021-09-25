//
// Created by user on 9/25/2021.
//

#include <sstream>
#include "UpdateSettingsCmd.h"

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
        std::stringstream iterator(response);
        char separator = ' ';
        //todo is correct?
        getline(iterator, kStr, separator);
        metric = iterator.str();

        bool validK = true;
        try {
            k = std::stoi(kStr);
            // kStr = 123hgkjglk is not valid
            if (std::to_string(k) != kStr) {
                validK = false;
            }
        } catch (...) {
            validK = false;
        }

        bool validMetric = true;
        DistanceCalculator* distCalc = DistCalcFactory::create(metric);
        if (distCalc == nullptr) {
            validMetric = false;
        }

        if (validK && validMetric) {
            this->classifier->setK(k);
            //todo set distCalc

            this->dio->write("Updated successfully");
        } else if (!validK) {
            this->dio->write("Invalid K");
        } else if (!validMetric) {
            this->dio->write("Invalid Metric Name");
        }
    }
}
