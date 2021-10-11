#include "StandardIO.h"

string StandardIO::read() const {
    string message;
    std::getline(std::cin, message);
    return message;
}

void StandardIO::writeLine(const string &message) const {
    std::cout << message << std::endl;
}
