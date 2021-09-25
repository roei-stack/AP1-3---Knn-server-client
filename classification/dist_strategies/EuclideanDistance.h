#ifndef TESTCLASSIFIER_CPP_EUCLIDEANDISTANCE_H
#define TESTCLASSIFIER_CPP_EUCLIDEANDISTANCE_H

#include "DistanceCalculator.h"

class EuclideanDistance : public DistanceCalculator {
    double getDistance(const Classifiable& t1, const Classifiable& t2) const override;
    std::string metricName() const override;
};


#endif //TESTCLASSIFIER_CPP_EUCLIDEANDISTANCE_H
