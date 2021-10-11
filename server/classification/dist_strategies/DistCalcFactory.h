//
// Created by user on 9/25/2021.
//

#ifndef HW3_DISTCALCFACTORY_H
#define HW3_DISTCALCFACTORY_H

#include "DistanceCalculator.h"
#include "ChebyshevDistance.h"
#include "EuclideanDistance.h"
#include "ManhattenDistance.h"
#include <string>

using std::string;

class DistCalcFactory {
public:
    static DistanceCalculator* create(const string& type);
};


#endif //HW3_DISTCALCFACTORY_H
