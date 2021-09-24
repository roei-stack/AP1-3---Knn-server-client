#include "Iris.h"

Iris::Iris(double width, double sepalLength, double sepalWidth, double petalLength, std::string classification) :
width(width), sepalLength(sepalLength), petalLength(petalLength),
sepalWidth(sepalWidth), classification(std::move(classification)) {}

std::string Iris::getClassification() const {
    return this->classification;
}


void Iris::setClassification(std::string newClassification) {
    this->classification = newClassification;
}


void Iris::Print(std::ostream &os) const {
    char sep = ',';
    os << this->petalLength << sep << this->sepalWidth << sep <<
       this->sepalLength<< sep<< this->width << sep << this->classification;
}

std::vector<double> Iris::getCoordinates() const {
    std::vector<double> coordinates{this->width, this->sepalLength, this->sepalWidth, this->petalLength};
    return coordinates;
}
