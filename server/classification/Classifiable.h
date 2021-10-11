#ifndef ASS1_IRIS_H
#define ASS1_IRIS_H

#include <iostream>
#include <utility>
#include <string>
#include <vector>

class Classifiable {
private:
    const std::vector<double> coordinates;
    std::string classification;
    void Print(std::ostream& os) const;
public:
    explicit Classifiable(std::vector<double> point, std::string  classification = "");

    /**
     * @return the classification of this Classifiable
     */
    std::string getClassification() const;

    /**
     * @return the coordinates of this Classifiable
     */
    std::vector<double> getCoordinates() const;

    /**
     * printing
     */
    friend std::ostream& operator<<(std::ostream& out, const Classifiable& b);
};
#endif //ASS1_IRIS_H
