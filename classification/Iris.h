#ifndef ASS1_IRIS_H
#define ASS1_IRIS_H

#include <string>
#include <vector>
using namespace std;

class Iris {
private:
    const double width;
    const double sepalLength;
    const double sepalWidth;
    const double petalLength;
    string classification;
    void Print(ostream& os) const;
public:
    Iris(double width, double sepalLength, double sepalWidth, double petalLength,
         string  classification = "");

    string getClassification() const;
    /**
     * @return the 4D coordinates of this Iris
     */
    std::vector<double> getCoordinates() const;
    void setClassification(const string& newClassification);
    friend ostream& operator<<(ostream& out, const Iris& iris);
};
#endif //ASS1_IRIS_H
