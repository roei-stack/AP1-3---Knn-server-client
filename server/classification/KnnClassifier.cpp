#include "KnnClassifier.h"

vector<std::pair<string,vector<double>>> KnnClassifier::calculateConfusionMatrix() const {
    // checking first that the testing data and the results are well-defined
    if (this->testingData->empty()) {
        throw std::runtime_error("Error: cannot find testing data");
    }
    else if (this->results.empty()) {
        throw std::runtime_error("Error: cannot find classifying results");
    }
    // comparing between the testing data and the results...
    // list of unique classes
    vector<std::pair<string, int>> classes = countOccurences();
    const int N = (int) classes.size();
    vector<std::pair<string, vector<double>>> confusionMatrix;
    // resizing the 2D matrix to hold NxN values
    // confusionMatrix[i][j] = 100 * (j-classes that were classified as i-classes)/(total count of i-classes)%
    for (int row = 0; row < N; row++) {
        const string trueClassification = classes[row].first;
        const int totalClasses = classes[row].second;
        vector<double> currentRow(N);
        for (int col = 0; col < N; col++) {
            // checking how many (classes[col].first) predicted as (classes[row].first)?
            const string predictedClassification = classes[col].first;
            int counter = 0;
            for (int i = 0; i < this->testingData->size(); i++) {
                const string tru = this->testingData->at(i)->getClassification();
                const string predict = this->results.at(i);
                if (tru == trueClassification && predict == predictedClassification) {
                    counter++;
                }
            }
            currentRow[col] = 100 * ((double)counter / totalClasses);
        }
        confusionMatrix.emplace_back(trueClassification, currentRow);
    }
    return confusionMatrix;
}

/******************************GETTERS AND SETTERS**********************************/
vector <string> KnnClassifier::getResults() const {
    if (this->results.empty()) {
        throw std::runtime_error("Error: No results found!");
    }
    return this->results;
}

void KnnClassifier::setDistanceCalculatingMethod(const string &type) {
    DistanceCalculator* c = DistCalcFactory::create(type);
    if (c == nullptr) {
        throw std::runtime_error("Error: Invalid calculator type: " + type);
    }
    delete this->calculator;
    this->calculator = c;
}


int KnnClassifier::getK() const {
    return this->k;
}

void KnnClassifier::setK(int newK) {
    if (newK > 10 || newK < 1) {
        throw std::runtime_error("Error: K must be in range 1-10 inclusive");
    }
    this->k = newK;
}

void KnnClassifier::setTrainingData(vector<Classifiable*> *data) {
    this->resetAndCopyData(this->trainingData, data);
}

void KnnClassifier::setTestingData(vector<Classifiable*> *data) {
    this->resetAndCopyData(this->testingData, data);
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
    // todo why warning
    return maxPair.first;
}

void KnnClassifier::classifyAllTestingData() {
    if (this->trainingData->empty()) {
        throw std::runtime_error("Error: Training data is uninitialized or empty");
    }
    if (this->testingData->empty()) {
        throw std::runtime_error("Error: Testing data is uninitialized or empty");
    }
    // removing previous results
    this->results.clear();
    // classifying all T's in testingData
    for (Classifiable* t : *(this->testingData)) {
        const Classifiable& toClassify = *t;
        string classification = this->classify(toClassify);
        this->results.push_back(classification);
    }
}

void KnnClassifier::clearData(vector<Classifiable*> *data) {
    // used to delete pointers in vector but the vector itself can be reused - for classes members only
    for (auto i : *data) {
        delete i;
    }
    data->clear();
}


vector<std::pair<string, int>> KnnClassifier::countOccurences() const {
    vector<std::pair<string, int>> v;
    const int size = (int) this->testingData->size();
    // occurrences of each string in this->testingData
    // this efficient solution takes O(n) and uses hashing
    std::unordered_map<string, int> map;
    // Iterate through array elements and count frequencies
    for (int i = 0; i < size; i++) {
        map[this->testingData->at(i)->getClassification()]++;
    }
    // saving the frequencies to the vector
    v.reserve(map.size());
    for (std::pair<string, int> pair : map) {
        v.emplace_back(pair.first, pair.second);
    }
    return v;
}

string KnnClassifier::getMetricName() const {
    return this->calculator->metricName();
}

void KnnClassifier::resetAndCopyData(vector<Classifiable *> *oldData, vector<Classifiable *> *newData) {
    if (oldData == newData) {
        //same data, no changes/deletions are required
        return;
    }
    if (newData == nullptr) {
        throw std::runtime_error("Error: The new data is undefined (nullptr)");
    }
    newData->shrink_to_fit();
    this->clearData(oldData);
    // cleaning the vector
    this->clearData(oldData);
    std::copy(newData->begin(), newData->end(), std::back_inserter(*oldData));
    //saving space
    oldData->shrink_to_fit();
    delete newData;
}

KnnClassifier::~KnnClassifier() {
    clearData(this->trainingData);
    delete this->trainingData;
    clearData(this->testingData);
    delete this->testingData;
    delete this->calculator;
}
