#include "Reader.h"
#include "LineToClassifiableConverter.h"

/**
 * @param filePath the path to the input file
 */
Reader::Reader(const std::string& filePath) {
    this->file.open(filePath);
    // taking care of bad inputs
    if (!this->file.is_open()) {
        throw std::runtime_error("Error: Failed to initialize file reader at path " + filePath);
    }
}

/**
 * builds the database from the csv file, this operation allocates memory on the heap
 * @return a vector-list of pointers to heap-allocated Classifiable objects
 */
std::vector<Classifiable*>* Reader::buildDataset() {
    std::vector<Classifiable*> *data;
    data = new std::vector<Classifiable*>;
    std::string line;
    int lineCounter = 0;
    while (this->file >> line) {
        Classifiable* classifiable = LineToClassifiableConverter::convert(line, lineCounter);
        data->push_back(classifiable);
        lineCounter++;
    }
    // Requests the container to reduce its capacity to fit its size, so no memory is wasted
    data->shrink_to_fit();
    // closing the file as we finished using it
    this->close();
    return data;
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
