#ifndef ASS1_IRIS_H
#define ASS1_IRIS_H

#include "Classifiable.h"

class Iris : public Classifiable {
private:
    const double width;
    const double sepalLength;
    const double sepalWidth;
    const double petalLength;
    std::string classification;
    void Print(std::ostream& os) const override;
public:
    Iris(double width, double sepalLength, double sepalWidth, double petalLength,
         std::string  classification = "");

    std::string getClassification() const override;
    /**
     * @return the 4D coordinates of this Iris
     */
    std::vector<double> getCoordinates() const override;
    void setClassification(std::string newClassification) override;
};
#endif //ASS1_IRIS_H
