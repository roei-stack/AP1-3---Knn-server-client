#include "Classifiable.h"

Classifiable::Classifiable(std::vector<double> point, std::string classification) :
        coordinates(std::move(point)), classification(std::move(classification)) {}

std::string Classifiable::getClassification() const {
    return this->classification;
}

void Classifiable::setClassification(const std::string& newClassification) {
    this->classification = newClassification;
}


void Classifiable::Print(std::ostream &os) const {
    char separator = ',';
    for (double a : this->coordinates) {
        os << a << separator;
    }
    os << this->classification;
}

std::vector<double> Classifiable::getCoordinates() const {
    return this->coordinates;
}

std::ostream &operator<<(std::ostream &out, const Classifiable &b) {
    b.Print(out);
    return out;
}





