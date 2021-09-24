#ifndef ASS1_CLASSIFIABLE_H
#define ASS1_CLASSIFIABLE_H

#include <iostream>
#include <string>
#include <vector>

/**
 * interface of an classifiable object.
 */
class Classifiable {
private:
    virtual void Print(std::ostream& os) const = 0;
public:
    /** @return  string the classification of this. */
    virtual std::string getClassification() const = 0;
    virtual void setClassification(std::string newClassification) = 0;

    /** @return the coordinates of this classifiable */
    virtual std::vector<double> getCoordinates() const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Classifiable& b) {
        b.Print(out);
        return out;
    }

    virtual ~Classifiable() = default;
};


#endif //ASS1_CLASSIFIABLE_H