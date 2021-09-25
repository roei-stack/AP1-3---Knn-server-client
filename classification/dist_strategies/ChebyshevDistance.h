#ifndef HW3_CHEBYSHEVDISTANCE_H
#define HW3_CHEBYSHEVDISTANCE_H

class ChebyshevDistance : public DistanceCalculator {
    double getDistance(const Classifiable& t1, const Classifiable& t2) const override;
    std::string metricName() const override;
};

double ChebyshevDistance::getDistance(const Classifiable& t1, const Classifiable& t2) const {
    // CHE FORMULA : MAX(|X[i] - Y[i]|)
    double max = 0;
    vector<double> p1 = t1.getCoordinates();
    vector<double> p2 = t2.getCoordinates();
    for (int i = 0; i < p1.size(); i++) {
        double curr = std::abs(p1[i] - p2[i]);
        if (max < curr) {
            max = curr;
        }
    }
    return max;
}

std::string ChebyshevDistance::metricName() const {
    return "CHE";
}

#endif //HW3_CHEBYSHEVDISTANCE_H
