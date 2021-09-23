#ifndef HW3_KNNCLASSIFIER_H
#define HW3_KNNCLASSIFIER_H

#include "Classifier.h"

/**
 * knn classifier.
 * @param T is a classifiable - it has the following method:
 *     1. vector<string>* getCoordinates
 */
template<class T>
class KnnClassifier : public Classifier<T> {
private:
    int k;
    // pointer to any type of distance calculator
    DistanceCalculator<T>* calculator = new EuclideanDistance<T>();

    vector<T*>* trainingData;
    vector<T*>* testingData;
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
    void clearData(vector<T*> *data);

    /**
    * returns the classification of toClassify
    * @param toClassify T has the following method:
     *     1. vector<double> getCoordinates()
    * @return string
    */
    string classify(const T& toClassify) override;

public:
    KnnClassifier(int k, const string& calc, vector<T*> *trainingData, vector<T*> *testingData);
    void classifyAllTestingData() override;
    /**
     * @return the classifications in order
     */

    /****getters and setters****/
    vector<string>* getResults();
    int getK() const;
    void setK(int k);
    vector<T*>* getTrainingData() const override;
    void setTrainingData(vector<T*>* data) override;
    vector<T*>* getTestingData() const override;
    void setTestingData(vector<T*>* data) override;
    void setDistanceCalculatingMethod(const string& type);
    ~KnnClassifier() override;
};
/************Method's definitions************/
template<class T>
KnnClassifier<T>::KnnClassifier(int k, const string& calc, vector<T*> *trainingData, vector<T*> *testingData) : k(k) {
    this->setDistanceCalculatingMethod(calc);
    this->trainingData = trainingData;
    this->testingData = testingData;
}

/******************************GETTERS AND SETTERS**********************************/
template<class T>
vector <string> *KnnClassifier<T>::getResults() {
    return this->results;
}

template<class T>
void KnnClassifier<T>::setDistanceCalculatingMethod(const string& type) {
    if (!(type == "EUC" || type == "MAN" || type == "CHE")) {
        throw std::invalid_argument("Invalid distance method : " + type);
    }
    delete this->calculator;
    if (type == "EUC") {
        this->calculator = new EuclideanDistance<T>();
    }
    if (type == "MAN") {
        this->calculator = new ManhattenDistance<T>();
    }
    if (type == "CHE") {
        this->calculator = new ChebyshevDistance<T>();
    }
}

template<class T>
int KnnClassifier<T>::getK() const {
    return this->k;
}
template<class T>
void KnnClassifier<T>::setK(int newK) {
    if (k > 10 || k < 1) {
        throw std::invalid_argument("Invalid k value : " + k);
    }
    this->k = newK;
}

template<class T>
vector<T *> *KnnClassifier<T>::getTrainingData() const {
    return this->trainingData;
}
template<class T>
void KnnClassifier<T>::setTrainingData(vector<T*> *data) {
    this->trainingData = data;
}

template<class T>
vector<T *> *KnnClassifier<T>::getTestingData() const {
    return this->trainingData;
}
template<class T>
void KnnClassifier<T>::setTestingData(vector<T *> *data) {
    this->testingData = data;
}

/***********************************************************************************/
template<class T>
string KnnClassifier<T>::classify(const T& toClassify) {
    // sorting the data set according to the distance from toClassify
    class TComparatorByDistToToClassify {
    private:
        const T& toClassify;
        const DistanceCalculator<T>* distanceCalculator;
    public:
        explicit TComparatorByDistToToClassify(const T& toClassify, const DistanceCalculator<T>* distanceCalculator) :
                toClassify(toClassify), distanceCalculator(distanceCalculator) {}

        bool operator() (const T* t1,const T* t2) {
            return distanceCalculator->getDistance(*t1, toClassify) < distanceCalculator->getDistance(*t2, toClassify);
        }
    };
    TComparatorByDistToToClassify cmp(toClassify, this->calculator);
    nth_element(this->trainingData->begin(), this->trainingData->begin() + k, this->trainingData->end(), cmp);
    // choosing the classification
    return this->chooseBestClassification();
}

template<class T>
string KnnClassifier<T>::chooseBestClassification() {
    // voteMap will map classifications to the number of close neighbors that have them.
    std::map<string, int> votesMap;
    // maxPair will be the classification from voteMap with the highest value.
    std::pair<string, int> maxPair("", 0);

    int index = 0;
    for (T *current : *this->trainingData) {
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

template<class T>
void KnnClassifier<T>::classifyAllTestingData() {
    if (this->testingData == nullptr || this->trainingData == nullptr) {
        throw std::runtime_error("Testing/Training data is uninitialized");
    }
    this->results->clear();
    int size = this->testingData->size();
    for (T* t : *(this->testingData)) {
        const T& toClassify = *t;
        string classification = this->classify(toClassify);
        this->results->push_back(classification);
    }
}

template<class T>
void KnnClassifier<T>::clearData(vector<T*> *data) {
    for (auto i : *data) {
        delete i;
    }
    data->clear();
}

template<class T>
KnnClassifier<T>::~KnnClassifier() {
    delete this->calculator;
    delete this->results;
    clearData(this->trainingData);
    clearData(this->testingData);
    delete this->trainingData;
    delete this->testingData;
}

#endif //HW3_KNNCLASSIFIER_H
