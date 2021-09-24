#include "Reader.h"

/**
 * @param filePath the path to the input file
 */
Reader::Reader(const string& filePath) {
    this->file.open(filePath);
    // taking care of bad inputs
    if (!this->file.is_open()) {
        throw invalid_argument("Failed to initialize file reader at path " + filePath);
    }
}

/**
 * builds the database from the csv file, this operation allocates memory on the heap
 * @return a vector-list of pointers to heap-allocated Classifiable objects
 */
vector<Classifiable*>* Reader::buildDataset() {
    vector<Classifiable*> *data;
    data = new vector<Classifiable*>;
    string line;
    while (this->file >> line) {
        Classifiable* classifiable = parseLine(line);
        data->push_back(classifiable);
    }
    // Requests the container to reduce its capacity to fit its size, so no memory is wasted
    data->shrink_to_fit();
    // closing the file as we finished using it
    this->close();
    return data;
}

/**
 * translates a string line into an object
 * @param line the given line
 * @return a pointer to classified object
 * remember to free the database
 */
Classifiable* Reader::parseLine(const string& line) {
    vector<double> coordinates;
    string classification;
    // we will iterate over the line using the ',' character as our separator
    stringstream iterator(line);
    // we will store our tokens here, last token should be the classification
    vector<string> tokens;

    /*
     * while (there are still ',')
     *      save current token
    */
    char separator = ',';
    string currentString;
    while (getline(iterator, currentString, separator)) {
        tokens.push_back(currentString);
    }
    // the number of coordinates is the amount of tokens - 1 (because the last token is the classification)
    int amountOfCoordinates = (int) tokens.size() - 1;
    if (amountOfCoordinates <= 0) {
        throw runtime_error("could not parse line" + line);
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

/**
 * closes the file
 */
void Reader::close() {
    this->file.close();
}

Reader::~Reader() {
    this->close();
}
