#include "ClassifyingServerCH.h"


void ClassifyingServerCH::HandleClient(TcpSocket* clientSocket) {
    //todo
    clientSocket->close();
    delete clientSocket;
}



