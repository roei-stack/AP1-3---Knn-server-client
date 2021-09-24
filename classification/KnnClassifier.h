#ifndef HW3_KNNCLASSIFIER_H
#define HW3_KNNCLASSIFIER_H

#include "Classifier.h"

/**
 * knn classifier.
 * @param T is a classifiable - it has the following method:
 *     1. vector<string>* getCoordinates
 *     2. string getClassification()
 */
class KnnClassifier : public Classifier {
private:
    int k;
    // pointer to any type of distance calculator
    DistanceCalculator* calculator = new EuclideanDistance();

    vector<Classifiable*>* trainingData;
    vector<Classifiable*>* testingData;
    // the classifier's results, in the original order : {class1, class2, ...}
    vector<string>* results = new vector<string>();

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

    /**
    * returns the classification of toClassify
    * @param toClassify T has the following method:
     *     1. vector<double> getCoordinates()
    * @return string
    */
    string classify(const Classifiable& toClassify) override;

public:
    KnnClassifier(int k, const string& calc, vector<Classifiable*> *trainingData, vector<Classifiable*> *testingData);
    void classifyAllTestingData() override;
    vector<vector<double>> calculateConfusionMatrix() const override;
    /**
     * @return the classifications in order
     */

    /****getters and setters****/
    vector<string>* getResults() const override;
    int getK() const override;
    void setK(int k) override;
    vector<Classifiable*>* getTrainingData() const override;
    void setTrainingData(vector<Classifiable*>* data) override;
    vector<Classifiable*>* getTestingData() const override;
    void setTestingData(vector<Classifiable*>* data) override;
    void setDistanceCalculatingMethod(const string& type) override;
    ~KnnClassifier() override;
};
/************Method's definitions************/
KnnClassifier::KnnClassifier(int k, const string& calc, vector<Classifiable*> *trainingData, vector<Classifiable*> *testingData) : k(k) {
    this->setDistanceCalculatingMethod(calc);
    this->trainingData = trainingData;
    this->testingData = testingData;
}

vector<vector<double>> KnnClassifier::calculateConfusionMatrix() const {
    // checking first that the testing data and the results are well-defined
    if (this->testingData->empty() || this->testingData == nullptr) {
        throw std::runtime_error("cannot find testing data");
    }
    if (this->results->empty() || this->results == nullptr) {
        throw std::runtime_error("cannot find classifying results");
    }
    // comparing between the testing data and the results...
    // todo - define the size of N - how many classes there are
    const int N = 10;
    vector<vector<double>> confusionMatrix;
    // resizing the 2D matrix to hold NxN values
    confusionMatrix.resize(N, vector<double>(N));
    // todo - confusionMatrix[i][j] = 100 * (j-classes that were classified as i-classes)/(total count of j-classes)%
    return confusionMatrix;
}

/******************************GETTERS AND SETTERS**********************************/
vector <string> *KnnClassifier::getResults() const {
    return this->results;
}

void KnnClassifier::setDistanceCalculatingMethod(const string& type) {
    if (!(type == "EUC" || type == "MAN" || type == "CHE")) {
        throw std::invalid_argument("Invalid distance method : " + type);
    }
    delete this->calculator;
    if (type == "EUC") {
        this->calculator = new EuclideanDistance();
    }
    if (type == "MAN") {
        this->calculator = new ManhattenDistance();
    }
    if (type == "CHE") {
        this->calculator = new ChebyshevDistance();
    }
}

int KnnClassifier::getK() const {
    return this->k;
}

void KnnClassifier::setK(int newK) {
    if (k > 10 || k < 1) {
        throw std::invalid_argument(&"Invalid k value : " [k]);
    }
    this->k = newK;
}

vector<Classifiable*> *KnnClassifier::getTrainingData() const {
    return this->trainingData;
}

void KnnClassifier::setTrainingData(vector<Classifiable*> *data) {
    this->trainingData = data;
}


vector<Classifiable*> *KnnClassifier::getTestingData() const {
    return this->trainingData;
}

void KnnClassifier::setTestingData(vector<Classifiable*> *data) {
    this->testingData = data;
}

/***********************************************************************************/

string KnnClassifier::classify(const Classifiable& toClassify) {
    // sorting the data set according to the distance from toClassify
    class TComparatorByDistToToClassify {
    private:
        const Classifiable& toClassify;
        const DistanceCalculator* distanceCalculator;
    public:
        explicit TComparatorByDistToToClassify(const Classifiable& toClassify, const DistanceCalculator* distanceCalculator) :
                toClassify(toClassify), distanceCalculator(distanceCalculator) {}
        bool operator() (const Classifiable* t1,const Classifiable* t2) {
            return distanceCalculator->getDistance(*t1, toClassify) < distanceCalculator->getDistance(*t2, toClassify);
        }
    };
    TComparatorByDistToToClassify cmp(toClassify, this->calculator);
    nth_element(this->trainingData->begin(), this->trainingData->begin() + k, this->trainingData->end(), cmp);
    // choosing the classification
    return this->chooseBestClassification();
}

string KnnClassifier::chooseBestClassification() {
    // voteMap will map classifications to the number of close neighbors that have them.
    std::map<string, int> votesMap;
    // maxPair will be the classification from voteMap with the highest value.
    std::pair<string, int> maxPair("", 0);
    int index = 0;
    for (Classifiable *current : *this->trainingData) {
        // we need only the first k
        if (index == this->k) {
            break;
        }
        index++;
        string classification = current->getClassification();
        // updating votesMap
        if (votesMap.count(classification) == 0) {
            votesMap[classification] = 1;
        } else {
            votesMap[classification]++;
        }
        // updating maxPair after the change in the votesMap
        auto it = votesMap.find(classification);
        if (it->second > maxPair.second) {
            maxPair = *it;
        }
    }
    return maxPair.first;
}

void KnnClassifier::classifyAllTestingData() {
    if (this->trainingData->empty() || this->trainingData == nullptr) {
        throw std::runtime_error("Training data is uninitialized or empty");
    }
    if (this->testingData->empty() || this->testingData == nullptr) {
        throw std::runtime_error("Testing data is uninitialized or empty");
    }
    // removing previous results
    this->results->clear();
    // classifying all T's in testingData
    for (Classifiable* t : *(this->testingData)) {
        const Classifiable& toClassify = *t;
        string classification = this->classify(toClassify);
        this->results->push_back(classification);
    }
}

void KnnClassifier::clearData(vector<Classifiable*> *data) {
    // used to delete pointers in vector but the vector itself can be reused - for classes members only
    for (auto i : *data) {
        delete i;
    }
    data->clear();
}

KnnClassifier::~KnnClassifier() {
    clearData(this->trainingData);
    delete this->trainingData;
    clearData(this->testingData);
    delete this->testingData;
    delete this->calculator;
    delete this->results;
}
#endif //HW3_KNNCLASSIFIER_H
