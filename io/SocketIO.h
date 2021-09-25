#ifndef HW3_SOCKETIO_H
#define HW3_SOCKETIO_H

#include "DefaultIO.h"

class SocketIO : public DefaultIO {
private:
    TcpSocket* socket;
public:
    explicit SocketIO(TcpSocket* tcpSocket);
    string read() const override;
    void write(const string& message) const override;
};

SocketIO::SocketIO(TcpSocket *tcpSocket) : socket(tcpSocket) {}

string SocketIO::read() const {
    return this->socket->receive();
}

void SocketIO::write(const string &message) const {
    this->socket->send(message);
}

#endif //HW3_SOCKETIO_H
