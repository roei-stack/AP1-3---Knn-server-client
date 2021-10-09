
#ifndef HW3_ICLIENTHANDLER_H
#define HW3_ICLIENTHANDLER_H

#include "TcpSocket.h"
#include "DefaultIO.h"

class IClientHandler {
public:
    virtual void HandleClient(TcpSocket* clientSocket) = 0;
};


#endif //HW3_ICLIENTHANDLER_H
