#include <iostream>
#include "TcpServerSocket.h"

TcpServerSocket::TcpServerSocket(int port, const char *ip) {
    this->socketId = socket(AF_INET, SOCK_STREAM, 0);
    if (this->socketId < 0) {
        perror("error creating socket");
    }
    // we only want the main server to be unblocked
    // because we want the regular sockets to wait for each other
    // for example: a client waits for the server to finish classifying...
    this->unblockSocket();
    // bind and listen...
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    if (strcmp(ip, "") != 0) {
        sin.sin_addr.s_addr = inet_addr(ip);
    } else {
        sin.sin_addr.s_addr = INADDR_ANY;
    }
    sin.sin_port = htons(port);

    if (bind(this->socketId, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(this->socketId, CLIENT_QUEUE_SIZE) < 0) {
        perror("error listening to a socket");
    }
}

/** this function changes the socket to be non blocking, so we can manage timeouts easily */
void TcpServerSocket::unblockSocket() const {
    // this should make the socket non blocking
    // i actually have no idea wtf i just typed i hope it works
    int flags = fcntl(this->socketId, F_GETFL);
    if (flags < 0) {
        perror("could not get flags on TCP listening socket");
    }
    // wtf is this
    if (fcntl(this->socketId, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("could not set TCP listening socket to be non-blocking");
    }
}

bool TcpServerSocket::select() const {
}


TcpSocket TcpServerSocket::accept(double timeout, double frequency) const {
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);

    /*
     * while: counter has not reached timeout:
     *      try to accept
     *      if accept failed:
     *           if there are no clients --> sleep and increase the counter
     *           if there was error accepting --> print the error & break
     *      else --> return the accepted client socket
     * if we reached timeout --> throw exception, the server will handle it
     */
    double counter = 0;
    while (counter <= timeout) {
        std::cout << "yes\n";
        int client_sock = ::accept(this->socketId,  (struct sockaddr *) &client_sin,  &addr_len);
        if (client_sock < 0) {
            if (errno == EWOULDBLOCK) {
                // no pending connections
                usleep((useconds_t) (frequency * 1000));
                counter += frequency;
            } else {
                perror("error accepting client");
                break;
            }
        } else {
            return TcpSocket(client_sock);
        }
    }
    throw std::runtime_error("connection timed out");
}

void TcpServerSocket::close() {
    ::close(this->socketId);
    this->closed = true;
}

bool TcpServerSocket::isClosed() const {
    return this->closed;
}

