#ifndef HW3_READER_H
#define HW3_READER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Classifiable.h"
using namespace std;

/**
 * This class is responsible to parse a csv file given it's path
 */
class Reader {
private:
    ifstream file;
    void close();
    Classifiable* parseLine(const string& line);
public:
    explicit Reader(const string& filePath);
    vector<Classifiable*>* buildDataset();
    ~Reader();
};
#endif //HW3_READER_H
