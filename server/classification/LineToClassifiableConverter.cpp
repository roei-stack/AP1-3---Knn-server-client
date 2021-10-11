//
// Created by user on 9/26/2021.
//

#include "LineToClassifiableConverter.h"

Classifiable *LineToClassifiableConverter::convert(const std::string &line, int errorCode) {
    std::vector<double> coordinates;
    std::string classification;
    // we will iterate over the line using the ',' character as our separator
    std::stringstream iterator(line);
    // we will store our tokens here, last token should be the classification
    std::vector<std::string> tokens;
    /*
     * while (there are still ',')
     *      save current token
    */
    char separator = ',';
    std::string currentString;
    while (getline(iterator, currentString, separator)) {
        tokens.push_back(currentString);
    }
    // the number of coordinates is the amount of tokens - 1 (because the last token is the classification)
    int amountOfCoordinates = (int) tokens.size() - 1;
    if (amountOfCoordinates <= 0) {
        throw std::runtime_error("Error: could not parse line #" + std::to_string(errorCode) + "->\"" + line + "\"");
    }
    coordinates.reserve(amountOfCoordinates);
    for (int i = 0; i < amountOfCoordinates; i++) {
        // if std::stod could not convert an exception will be thrown
        coordinates.push_back(stod(tokens[i]));
    }
    // the classification is the last value in "tokens"
    classification = tokens[amountOfCoordinates];
    auto* classifiable = new Classifiable(coordinates, classification);
    return classifiable;
}
