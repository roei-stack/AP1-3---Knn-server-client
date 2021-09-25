//
// Created by user on 9/24/2021.
//

#include "ClassifyingServerCH.h"

void ClassifyingServerCH::HandleClient(Socket* clientSocket) {



    clientSocket->close();
    delete clientSocket;
}
