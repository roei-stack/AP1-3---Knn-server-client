#ifndef ASS1_CLASSIFIER_H
#define ASS1_CLASSIFIER_H

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <unordered_map>
#include "DistCalcFactory.h"
#include "DistanceCalculator.h"

using std::vector;
using std::string;

class IClassifier {
public:
    virtual void classifyAllTestingData() = 0;
    virtual vector<string>* getResults() const = 0;
    virtual vector<std::pair<string, vector<double>>> calculateConfusionMatrix() const = 0;
    /*************GETTERS AND SETTERS***************/
    virtual int getK() const = 0;
    virtual void setK(int k) = 0;
    virtual vector<Classifiable*>* getTrainingData() const = 0;
    virtual void setTrainingData(vector<Classifiable*>* data) = 0;
    virtual vector<Classifiable*>* getTestingData() const = 0;
    virtual string getMetricName() const = 0;
    virtual void setTestingData(vector<Classifiable*>* data) = 0;
    virtual void setDistanceCalculatingMethod(const string& type) = 0;
    /** virtual destructor **/
    virtual ~IClassifier() = default;
};
#endif //ASS1_CLASSIFIER_H
