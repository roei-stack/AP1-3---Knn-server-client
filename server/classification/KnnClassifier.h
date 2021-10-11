#ifndef HW3_KNNCLASSIFIER_H
#define HW3_KNNCLASSIFIER_H

#include "IClassifier.h"

/**
 * knn classifier.
 * @param T is a classifiable - it has the following method:
 *     1. vector<string>* getCoordinates
 *     2. string getClassification()
 */
class KnnClassifier : public IClassifier {
private:
    // default settings: k = 5, euclidean distance method
    int k = 5;
    // pointer to any type of distance calculator
    DistanceCalculator* calculator = new EuclideanDistance();
    vector<Classifiable*>* trainingData = new vector<Classifiable*>;
    vector<Classifiable*>* testingData = new vector<Classifiable*>;
    // the classifier's results, in the original order : {class1, class2, ...}
    vector<string> results;

    /**
     * @return works out the best classification given the k nearest neighbours
     */
    string chooseBestClassification();

    /**
     * clear a vector of pointers (deletes data):
     *  1. delete each pointer
     *  2. call vector.clear()
     * now to vector is ready to reassign
     */
    void clearData(vector<Classifiable*> *data);
    /** used by setTest and setTrain functions */
    void resetAndCopyData(vector<Classifiable *> *oldData, vector<Classifiable *> *newData);

    /** @return list of all possible classifications with how many times they appeared in the testing data */
    vector<std::pair<string, int>> countOccurences() const;

    /**
    * returns the classification of toClassify
    * @param toClassify Classifiable to classify
    * @return string
    */
    string classify(const Classifiable& toClassify);
public:
    KnnClassifier() = default;
    void classifyAllTestingData() override;
    vector<std::pair<string, vector<double>>> calculateConfusionMatrix() const override;
    /****getters and setters****/
    vector<string> getResults() const override;

    int getK() const override;
    void setK(int k) override;

    string getMetricName() const override;
    void setDistanceCalculatingMethod(const string& type) override;

    void setTrainingData(vector<Classifiable*>* data) override;
    void setTestingData(vector<Classifiable*>* data) override;

    ~KnnClassifier() override;
};


#endif //HW3_KNNCLASSIFIER_H
