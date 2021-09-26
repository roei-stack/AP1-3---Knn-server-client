#ifndef HW3_STANDARDIO_H
#define HW3_STANDARDIO_H

#include "DefaultIO.h"
#include <iostream>

class StandardIO : public DefaultIO{
public:
    string read() const override;
    void write(const string& message) const override;
};

#endif //HW3_STANDARDIO_H
