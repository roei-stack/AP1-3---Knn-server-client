cmake_minimum_required(VERSION 3.16)
project(hw3)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw3 testClassifier.cpp
        classification/Reader.cpp classification/Reader.h
        classification/Classifiable.cpp classification/Classifiable.h
        classification/IClassifier.h
        classification/KnnClassifier.h
        classification/DistanceCalculator.h
        classification/EuclideanDistance.h
        classification/ManhattenDistance.h
        classification/ChebyshevDistance.h
        io/DefaultIO.h io/StandardIO.h io/SocketIO.h
        sockets/TcpServerSocket.h sockets/TcpServerSocket.cpp
        sockets/TcpSocket.h sockets/TcpSocket.cpp
        commands/ICommand.h
        commands/UploadCmd.h)
