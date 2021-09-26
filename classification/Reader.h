#ifndef HW3_READER_H
#define HW3_READER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Classifiable.h"

/**
 * This class is responsible to parse a csv file given it's path
 */
class Reader {
private:
    std::ifstream file;
    void close();
public:
    explicit Reader(const std::string& filePath);
    std::vector<Classifiable*>* buildDataset();
    ~Reader();
};
#endif //HW3_READER_H
