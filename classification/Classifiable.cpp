#include "Classifiable.h"

Classifiable::Classifiable(double width, double sepalLength, double sepalWidth, double petalLength, std::string classification) :
width(width), sepalLength(sepalLength), petalLength(petalLength),
sepalWidth(sepalWidth), classification(std::move(classification)) {}

std::string Classifiable::getClassification() const {
    return this->classification;
}


void Classifiable::setClassification(std::string newClassification) {
    this->classification = newClassification;
}


void Classifiable::Print(std::ostream &os) const {
    char sep = ',';
    os << this->petalLength << sep << this->sepalWidth << sep <<
       this->sepalLength<< sep<< this->width << sep << this->classification;
}

std::vector<double> Classifiable::getCoordinates() const {
    std::vector<double> coordinates{this->width, this->sepalLength, this->sepalWidth, this->petalLength};
    return coordinates;
}

std::ostream &operator<<(std::ostream &out, const Classifiable &b) {
    b.Print(out);
    return out;
}
