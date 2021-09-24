#ifndef ASS1_IRIS_H
#define ASS1_IRIS_H

#include <iostream>
#include <string>
#include <vector>

class Classifiable {
private:
    const double width;
    const double sepalLength;
    const double sepalWidth;
    const double petalLength;
    std::string classification;
    void Print(std::ostream& os) const;
public:
    Classifiable(double width, double sepalLength, double sepalWidth, double petalLength,
         std::string  classification = "");

    std::string getClassification() const;
    /**
     * @return the coordinates of this Classifiable
     */
    std::vector<double> getCoordinates() const;
    void setClassification(std::string newClassification);
    friend std::ostream& operator<<(std::ostream& out, const Classifiable& b);
};
#endif //ASS1_IRIS_H
