#ifndef HW3_DISTANCECALCULATOR_H
#define HW3_DISTANCECALCULATOR_H

#include <cmath>

using std::vector;

/**
 * Calculator for distances using strategy, and thread-safe singleton patterns
 * An interface that allows multiple ways to calculate distances between objects
 * @tparam T the object's type. T must implement a method called "vector<string>* getCoordinates()"
 */
class DistanceCalculator {
public:
    virtual double getDistance(const Classifiable& t1, const Classifiable& t2) const = 0;
    ~DistanceCalculator() = default;
};

#endif //HW3_DISTANCECALCULATOR_H
