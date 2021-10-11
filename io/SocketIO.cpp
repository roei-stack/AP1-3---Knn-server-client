
#include "SocketIO.h"

SocketIO::SocketIO(TcpSocket *tcpSocket) : socket(tcpSocket) {}

string SocketIO::read() const {
    return this->socket->receive();
}

void SocketIO::writeLine(const string &message) const {
    std::stringstream msg;
    msg << message << std::endl;
    this->socket->send(msg.str());
}

