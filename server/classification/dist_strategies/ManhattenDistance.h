#ifndef TESTCLASSIFIER_CPP_MANHATTENDISTANCE_H
#define TESTCLASSIFIER_CPP_MANHATTENDISTANCE_H

#include "DistanceCalculator.h"

class ManhattenDistance : public DistanceCalculator {
    double getDistance(const Classifiable& t1, const Classifiable& t2) const override;
    std::string metricName() const override;
};


#endif //TESTCLASSIFIER_CPP_MANHATTENDISTANCE_H
