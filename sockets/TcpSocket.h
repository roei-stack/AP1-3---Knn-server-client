#ifndef ASS2_TCPSOCKET_H
#define ASS2_TCPSOCKET_H

#include <string>
#include <stdexcept>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define BUFFER 4096


class TcpSocket {
private:
    bool closed = false;
    int socketId;
public:
    explicit TcpSocket(int socketId);
    TcpSocket(const char* othersIp, int othersPort);
    void send(const std::string& message) const;
    std::string receive() const;
    void close();
    bool isClosed() const;
};

#endif //ASS2_TCPSOCKET_H
