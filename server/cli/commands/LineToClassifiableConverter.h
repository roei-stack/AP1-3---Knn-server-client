//
// Created by user on 9/26/2021.
//

#ifndef HW3_LINETOCLASSIFIABLECONVERTER_H
#define HW3_LINETOCLASSIFIABLECONVERTER_H

#include <sstream>
#include "Classifiable.h"

class LineToClassifiableConverter {
public:
    /**
     * translates a string line into an object
     * @param line the given line
     * @return a pointer to classified object
     * remember to free the database
    */
    static Classifiable* convert(const std::string& line, int errorCode);
};


#endif //HW3_LINETOCLASSIFIABLECONVERTER_H
