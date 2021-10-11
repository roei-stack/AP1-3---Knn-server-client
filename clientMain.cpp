#include <iostream>
#include <fstream>
#include "cli/CLI.h"
#include "sockets/TcpSocket.h"
#include "io/SocketIO.h"

void sendToServer(const string& msg, const SocketIO& io) {
    // checking if client entered a valid file path
    std::ifstream f(msg);
    if (!f) {
        // not a file path
        io.writeLine(msg);
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
    io.writeLine(content.str());
}

void saveResultsToFile(const string& path, const string& output) {
    std::ofstream myFile;
    myFile.open(path);
    if (!myFile.is_open()) {
        std::cout << "Error: " << path << "is not a proper path" << std::endl;
        return;
    }
    myFile << output;
    std::cout << "file saved successfully" << std::endl;
    myFile.close();
}

int main() {
    TcpSocket socket("127.0.0.1", 5487);
    SocketIO io(&socket);
    std::cout << io.read();
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
        if (output.substr(0, output.find('\n')) == "save"
        || output.substr(0, output.find("\r\n")) == "save") {
            string path;
            std::cout << "enter a local path to save file, remember to add \"../\" before a reference path"
            << std::endl;
            getline(std::cin, path);
            saveResultsToFile(path, output);
            continue;
        }
        std::cout << output;
    }
    socket.close();
    std::cout << "Connection closed" << std::endl;
}
