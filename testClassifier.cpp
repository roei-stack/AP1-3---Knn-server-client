#include <iostream>
#include "classification/Reader.h"
#include "classification/Classifier.h"
#include "classification/KnnClassifier.h"

using std::string;

int main() {
    string classifiedPath = "../classified.csv";
    string unclassifiedPath = "../unclassified.csv";
    //// initializing the reader for classified and unclassified
    Reader reader(classifiedPath);
    Reader otherReader(unclassifiedPath);
    //// loading the datasets
    vector<Iris*>* classifiedData = reader.buildDataset();
    vector<Iris*>* unclassifiedData = otherReader.buildDataset();
    // applying classifier
    EuclideanDistance<Iris> calculator;

    // creating classifier, classifying all and getting results
    KnnClassifier<Iris> classifier(5, &calculator, nullptr, unclassifiedData);
    classifier.setTrainingData(classifiedData);
    classifier.classifyAllTestingData();
    vector<string>* ans = classifier.getResults();

    // printing results
    for (const string& s : *ans) {
        std::cout << s << std::endl;
    }
    return 0;
}
