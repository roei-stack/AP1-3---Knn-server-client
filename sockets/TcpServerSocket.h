#ifndef ASS2_TCPSERVERSOCKET_H
#define ASS2_TCPSERVERSOCKET_H

#include "TcpSocket.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

class TcpServerSocket {
private:
    bool closed = false;
    int socketId;
    TcpSocket clientSocket;
public:
    explicit TcpServerSocket(int port, const char* ip = "");

    TcpSocket* accept();

    void endCommunicationWithClient();

    void close();

    bool isClosed() const;
};
#endif //ASS2_TCPSERVERSOCKET_H
