#ifndef HW3_DISTANCECALCULATOR_H
#define HW3_DISTANCECALCULATOR_H

#include <cmath>
using std::vector;

/**
 * An interface that allows multiple ways to calculate distances between objects
 * @tparam T the object's type. T must implement a method called "vector<string>* getCoordinates()"
 */
template<class T>
class DistanceCalculator {
public:
    virtual double getDistance(const T& t1, const T& t2) const = 0;
};

#endif //HW3_DISTANCECALCULATOR_H
