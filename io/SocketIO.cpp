
#include "SocketIO.h"

SocketIO::SocketIO(TcpSocket *tcpSocket) : socket(tcpSocket) {}

string SocketIO::read() const {
    /*
    // receive method may return many lines at once, so we will separate them using the endLine terminator
    string line = this->socket->receive();
    std::stringstream ss(line);
    std::string to;
    while(std::getline(ss,to,'\n\r')) {
        //to
    }
     */
    return this->socket->receive();
}

void SocketIO::writeLine(const string &message) const {
    std::stringstream msg;
    msg << message << std::endl;
    this->socket->send(msg.str());
}

