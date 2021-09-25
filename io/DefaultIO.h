#ifndef HW3_DEFAULTIO_H
#define HW3_DEFAULTIO_H

#include <string>

using std::string;

class DefaultIO {
public:
    virtual string read() const = 0;
    virtual void write(const string& message) const = 0;
};

#endif //HW3_DEFAULTIO_H
