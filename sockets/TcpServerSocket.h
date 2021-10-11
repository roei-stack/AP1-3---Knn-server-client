#ifndef ASS2_TCPSERVERSOCKET_H
#define ASS2_TCPSERVERSOCKET_H

#include "TcpSocket.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>

#define CLIENT_QUEUE_SIZE 5

class TcpServerSocket {
private:
    bool closed = false;
    int socketId;
    void unblockSocket() const;
    bool select() const;
public:
    explicit TcpServerSocket(int port, const char* ip = "");

    /**
     * tries to accept a client
     * @param timeout how much time should the function wait for
     * @param frequency how frequent should the server ask for new connections
     * @return the new client socket
     * if accept failed, will either print an error or throw a timeout exception
     */
    TcpSocket accept(double timeout = 30000, double frequency = 1000) const;

    void close();

    bool isClosed() const;
};
#endif //ASS2_TCPSERVERSOCKET_H
