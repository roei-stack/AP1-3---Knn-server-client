
#include "SocketIO.h"

SocketIO::SocketIO(TcpSocket *tcpSocket) {}

string SocketIO::read() const {
    // receive method may return many lines at once, so we will separate them using the endLine terminator
    string line = this->socket->receive();

    std::stringstream ss(line);
    std::string to;

    /*
    while(std::getline(ss,to,'\n\r')){
        //to
    }
*/


    return this->socket->receive();
}

void SocketIO::write(const string &message) const {
    this->socket->send(message);
}

