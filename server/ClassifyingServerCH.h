//
// Created by user on 9/24/2021.
//

#ifndef HW3_CLASSIFYINGSERVERCH_H
#define HW3_CLASSIFYINGSERVERCH_H

#include "IClientHandler.h"

class ClassifyingServerCH : public IClientHandler {

public:
    void HandleClient(Socket* clientSocket) override;
};


#endif //HW3_CLASSIFYINGSERVERCH_H
