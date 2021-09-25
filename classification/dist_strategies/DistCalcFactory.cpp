//
// Created by user on 9/25/2021.
//

#include "DistCalcFactory.h"

DistanceCalculator *DistCalcFactory::create(string& type) {
    if (type == "EUC") {
        return new EuclideanDistance();
    } else if (type == "MAN") {
        return new ManhattenDistance();
    } else if (type == "CHE") {
        return new ChebyshevDistance();
    } else {
        return nullptr;
    }
}
