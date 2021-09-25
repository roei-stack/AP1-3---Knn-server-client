cmake_minimum_required(VERSION 3.16)
project(hw3)

set(CMAKE_CXX_STANDARD 11)

include_directories(classification classification/dist_strategies commands io server sockets)

add_executable(hw3 testClassifier.cpp
        classification/Reader.cpp classification/Reader.h
        classification/Classifiable.cpp classification/Classifiable.h
        classification/IClassifier.h
        classification/KnnClassifier.h
        classification/dist_strategies/DistanceCalculator.h
        classification/dist_strategies/EuclideanDistance.h
        classification/dist_strategies/ManhattenDistance.h
        classification/dist_strategies/ChebyshevDistance.h
        io/DefaultIO.h io/StandardIO.h io/SocketIO.h
        sockets/TcpServerSocket.h sockets/TcpServerSocket.cpp
        sockets/TcpSocket.h sockets/TcpSocket.cpp
        commands/ICommand.h
        commands/UploadCmd.h commands/UploadCmd.cpp commands/UpdateSettingsCmd.cpp commands/UpdateSettingsCmd.h)
