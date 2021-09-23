#ifndef HW3_EUCLIDEANDISTANCE_H
#define HW3_EUCLIDEANDISTANCE_H
#include "DistanceCalculator.h"

template <class T>
class EuclideanDistance : public DistanceCalculator<T> {
    double getDistance(const T& t1, const T& t2) const override;
};

template<class T>
double EuclideanDistance<T>::getDistance(const T &t1, const T &t2) const {
    // EUC FORMULA : SQRT(SUM((X[i] - Y[i])^2))
    double sum = 0;
    vector<double> p1 = t1.getCoordinates();
    vector<double> p2 = t2.getCoordinates();
    for (int i = 0; i < p1.size(); i++) {
        sum += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    }
    return sqrt(sum);
}
#endif //HW3_EUCLIDEANDISTANCE_H
