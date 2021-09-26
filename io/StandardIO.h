#ifndef HW3_STANDARDIO_H
#define HW3_STANDARDIO_H

#include "DefaultIO.h"
#include <iostream>

class StandardIO : public DefaultIO{
public:
    string read() const override;
    void write(const string& message) const override;
};

string StandardIO::read() const {
    string message;
    std::cin >> message;
    return message;
}

void StandardIO::write(const string &message) const {
    std::cout << message << std::endl;
}
#endif //HW3_STANDARDIO_H
