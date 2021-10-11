#include "TcpSocket.h"

TcpSocket::TcpSocket(int socketId) : socketId(socketId) {

}

TcpSocket::TcpSocket(const char *othersIp, int othersPort) {
    this->socketId = socket(AF_INET, SOCK_STREAM, 0);
    if (this->socketId < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(othersIp);
    sin.sin_port = htons(othersPort);

    if (connect(this->socketId, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
}

void TcpSocket::send(const std::string &message) const {
    long bytesSent = ::send(this->socketId, message.c_str(), message.size(), 0);
    if (bytesSent < 0) {
        perror("error sending message");
    }
}

std::string TcpSocket::receive() const {
    char buffer[BUFFER]{};
    long bytesRead = ::recv(this->socketId, buffer, BUFFER, 0);
    if (bytesRead < 0) {
        throw std::runtime_error("Error: failed receiving the message");
    }
    // converting to string type
    std::string str(buffer);
    return str;
}

void TcpSocket::close() {
    ::close(this->socketId);
    this->closed = true;
}

bool TcpSocket::isClosed() const {
    return this->closed;
}
