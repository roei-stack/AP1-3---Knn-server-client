//
// Created by Roei on 25/09/2021.
//

#include "EuclideanDistance.h"

double EuclideanDistance::getDistance(const Classifiable &t1, const Classifiable &t2) const {
    // EUC FORMULA : SQRT(SUM((X[i] - Y[i])^2))
    double sum = 0;
    vector<double> p1 = t1.getCoordinates();
    vector<double> p2 = t2.getCoordinates();
    for (int i = 0; i < p1.size(); i++) {
        sum += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    }
    return sqrt(sum);
}

std::string EuclideanDistance::metricName() const {
    return "EUC";
}
