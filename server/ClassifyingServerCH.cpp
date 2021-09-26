//
// Created by user on 9/24/2021.
//

#include "ClassifyingServerCH.h"

void ClassifyingServerCH::HandleClient(TcpSocket* clientSocket) {
    //todo



    clientSocket->close();
    delete clientSocket;
}
