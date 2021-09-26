
#include "StandardIO.h"

string StandardIO::read() const {
    string message;
    std::getline(std::cin, message);
    return message;
}

void StandardIO::write(const string &message) const {
    std::cout << message << std::endl;
}
