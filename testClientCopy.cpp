#include <iostream>
#include "CLI.h"
#include "classification/Reader.h"
#include "sockets/TcpSocket.h"
#include "io/SocketIO.h"
#include "server/ClassifyingServerCH.h"

void sendToServer(const string& msg, const SocketIO& io) {
    // checking if client entered a valid file path
    std::ifstream f(msg);
    if (!f) {
        // not a file path
        io.write(msg);
        return;
    }
    // if the user entered a file path
    // we will send the file to the server in one big CHUNKY BOI
    std::stringstream content;
    std::string current;
    while (f >> current) {
       content << current << ":";
    }
    content << "Done.";
    io.write(content.str());
}

int main() {
    TcpSocket socket("127.0.0.1", 6855);
    SocketIO io(&socket);
    std::cout << io.read() << std::endl;
    while (true) {
        string input, output;
        getline(std::cin, input);
        // allows us to send both files and literal strings
        sendToServer(input, io);
        output = io.read();
        // server will send exit before closing connection with a client
        if (output == "exit\n" || output == "exit\r\n") {
            std::cout << "Server has quit the session" << std::endl;
            break;
        }
        std::cout << output;
    }
    socket.close();
    std::cout << "Connection closed" << std::endl;
}
