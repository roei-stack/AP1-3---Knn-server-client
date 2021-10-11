
#include "DistCalcFactory.h"

DistanceCalculator *DistCalcFactory::create(const string& type) {
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
