#include "Iris.h"
#include <iostream>
#include <vector>

Iris::Iris(double width, double sepalLength, double sepalWidth, double petalLength, string  classification) :
width(width), sepalLength(sepalLength), petalLength(petalLength),
sepalWidth(sepalWidth), classification(std::move(classification)) {}

string Iris::getClassification() const {
    return this->classification;
}

void Iris::setClassification(const string& newClassification) {
    this->classification = newClassification;
}

void Iris::Print(ostream &os) const {
    char sep = ',';
    os << this->petalLength << sep << this->sepalWidth << sep <<
       this->sepalLength<< sep<< this->width << sep << this->classification;
}

ostream& operator<<(ostream& out, const Iris& iris) {
    iris.Print(out);
    return out;
}

std::vector<double> Iris::getCoordinates() const {
    std::vector<double> coordinates{this->width, this->sepalLength, this->sepalWidth, this->petalLength};
    return coordinates;
}
