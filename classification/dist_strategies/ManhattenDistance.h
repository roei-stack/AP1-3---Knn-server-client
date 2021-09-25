#ifndef HW3_MANHATTANDISTANCE_H
#define HW3_MANHATTANDISTANCE_H
#include "DistanceCalculator.h"

class ManhattenDistance : public DistanceCalculator {
    double getDistance(const Classifiable& t1, const Classifiable& t2) const override;
    std::string metricName() const override;
};

double ManhattenDistance::getDistance(const Classifiable& t1, const Classifiable& t2) const {
    // MAN FORMULA : SUM(|X[i] - Y[i]|)
    double sum = 0;
    vector<double> p1 = t1.getCoordinates();
    vector<double> p2 = t2.getCoordinates();
    for (int i = 0; i < p1.size(); i++) {
        sum += std::abs(p1[i] - p2[i]);
    }
    return sum;
}

std::string ManhattenDistance::metricName() const {
    return "MAN";
}

#endif //HW3_MANHATTANDISTANCE_H
