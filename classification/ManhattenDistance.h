#ifndef HW3_MANHATTANDISTANCE_H
#define HW3_MANHATTANDISTANCE_H
#include "DistanceCalculator.h"

template <class T>
class ManhattenDistance : public DistanceCalculator<T> {
    double getDistance(const T& t1, const T& t2) const override;
};

template<class T>
double ManhattenDistance<T>::getDistance(const T& t1, const T& t2) const {
    // MAN FORMULA : SUM(|X[i] - Y[i]|)
    double sum = 0;
    vector<double> p1 = t1.getCoordinates();
    vector<double> p2 = t2.getCoordinates();
    for (int i = 0; i < p1.size(); i++) {
        sum += abs(p1[i] - p2[i]);
    }
    return sum;
}
#endif //HW3_MANHATTANDISTANCE_H
