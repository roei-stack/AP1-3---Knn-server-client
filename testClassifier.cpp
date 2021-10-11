#include <thread>
#include "CLI.h"
#include "sockets/TcpServerSocket.h"
#include "io/SocketIO.h"

void handle(TcpSocket clientSock) {
    SocketIO io(&clientSock);
    CLI cli(&io);
    cli.start();
    clientSock.close();
}

int main() {
    // reminder -> reference paths start with "../"
    TcpServerSocket server(6855, "127.0.0.1");
    while (true) {
        try {
            // socket object to receive incoming clients
            // TIMEOUT is 30000ms with 1000ms delay by default
            TcpSocket client = server.accept();
            // displaying that new client has connected
            std::cout << "new client connected" << std::endl;
            //creating a new thread object
            auto *clientThread = new std::thread(handle, client);
        } catch (std::exception& e) {
            // todo handle connection timed out
            // 1 todo if any client connects, send "exit"
            // 2 todo check in client if server sent "exit"
            break;
        }
    }
}
