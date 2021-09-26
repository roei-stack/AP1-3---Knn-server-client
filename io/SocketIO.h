#ifndef HW3_SOCKETIO_H
#define HW3_SOCKETIO_H

#include "TcpSocket.h"
#include "DefaultIO.h"
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

class SocketIO : public DefaultIO {
private:
    TcpSocket* socket;
    vector<string> lines;
public:
    explicit SocketIO(TcpSocket* tcpSocket);
    string read() const override;
    void write(const string& message) const override;
};

#endif //HW3_SOCKETIO_H
