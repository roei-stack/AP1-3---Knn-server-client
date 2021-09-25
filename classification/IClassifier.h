#ifndef ASS1_CLASSIFIER_H
#define ASS1_CLASSIFIER_H

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include "DistanceCalculator.h"
#include "EuclideanDistance.h"
#include "ManhattenDistance.h"
#include "ChebyshevDistance.h"

using std::vector;
using std::string;

class IClassifier {
private:
    /**
     * returns the classification of c
     * @param toClassify to classify. must be an appropriate Classifiable such that
     *     c knows how to calculate it's coordinates in this Classifier's dataset.
     *     probably, it will have to be from the same type as them.
     *     **if other's type won't be appropriate, an exception may be thrown.**
     * @return string the guessed classification of toClassify
     */
    virtual string classify(const Classifiable& toClassify) = 0;
public:
    virtual void classifyAllTestingData() = 0;
    virtual vector<string>* getResults() const = 0;
    // todo - confusion matrix
    virtual vector<std::pair<string, vector<double>>> calculateConfusionMatrix() const = 0;
    /*************GETTERS AND SETTERS***************/
    virtual int getK() const = 0;
    virtual void setK(int k) = 0;
    virtual vector<Classifiable*>* getTrainingData() const = 0;
    virtual void setTrainingData(vector<Classifiable*>* data) = 0;
    virtual vector<Classifiable*>* getTestingData() const = 0;
    virtual void setTestingData(vector<Classifiable*>* data) = 0;
    virtual void setDistanceCalculatingMethod(const string& type) = 0;
    /** virtual destructor **/
    virtual ~IClassifier() = default;
};
#endif //ASS1_CLASSIFIER_H
