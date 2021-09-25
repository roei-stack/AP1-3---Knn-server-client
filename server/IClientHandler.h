//
// Created by user on 9/24/2021.
//

#ifndef HW3_ICLIENTHANDLER_H
#define HW3_ICLIENTHANDLER_H

#include "Socket.h"

class IClientHandler {
public:
    virtual void HandleClient(Socket* clientSocket) = 0;
};


#endif //HW3_ICLIENTHANDLER_H
