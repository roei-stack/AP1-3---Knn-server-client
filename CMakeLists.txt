cmake_minimum_required(VERSION 3.16)
project(hw3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(classification classification/dist_strategies commands io server sockets)

add_executable(hw3 testClassifier.cpp
        classification/Reader.cpp classification/Reader.h
        classification/Classifiable.cpp classification/Classifiable.h
        classification/IClassifier.h
        classification/dist_strategies/DistanceCalculator.h
        io/DefaultIO.h io/StandardIO.h io/SocketIO.h
        sockets/TcpServerSocket.h sockets/TcpServerSocket.cpp
        sockets/TcpSocket.h sockets/TcpSocket.cpp
        commands/ICommand.h
        commands/UploadCmd.h commands/UploadCmd.cpp
        commands/UpdateSettingsCmd.cpp commands/UpdateSettingsCmd.h
        classification/dist_strategies/DistCalcFactory.cpp classification/dist_strategies/DistCalcFactory.h
        commands/WriteResultsCmd.cpp commands/WriteResultsCmd.h
        commands/ClassifyCmd.cpp commands/ClassifyCmd.h
        classification/LineToClassifiableConverter.cpp classification/LineToClassifiableConverter.h
        commands/ConfusionMatrixCmd.cpp commands/ConfusionMatrixCmd.h
        server/IClientHandler.h
        server/ClassifyingServerCH.h server/ClassifyingServerCH.cpp server/CLI.cpp
        server/CLI.h classification/KnnClassifier.cpp classification/KnnClassifier.h
        classification/dist_strategies/EuclideanDistance.cpp classification/dist_strategies/ManhattenDistance.cpp
        classification/dist_strategies/ChebyshevDistance.cpp io/SocketIO.cpp io/StandardIo.cpp)

add_executable(testClient testClient.cpp
        classification/Reader.cpp classification/Reader.h
        classification/Classifiable.cpp classification/Classifiable.h
        classification/IClassifier.h
        classification/dist_strategies/DistanceCalculator.h
        io/DefaultIO.h io/StandardIO.h io/SocketIO.h
        sockets/TcpServerSocket.h sockets/TcpServerSocket.cpp
        sockets/TcpSocket.h sockets/TcpSocket.cpp
        commands/ICommand.h
        commands/UploadCmd.h commands/UploadCmd.cpp
        commands/UpdateSettingsCmd.cpp commands/UpdateSettingsCmd.h
        classification/dist_strategies/DistCalcFactory.cpp classification/dist_strategies/DistCalcFactory.h
        commands/WriteResultsCmd.cpp commands/WriteResultsCmd.h
        commands/ClassifyCmd.cpp commands/ClassifyCmd.h
        classification/LineToClassifiableConverter.cpp classification/LineToClassifiableConverter.h
        commands/ConfusionMatrixCmd.cpp commands/ConfusionMatrixCmd.h
        server/IClientHandler.h
        server/ClassifyingServerCH.h server/ClassifyingServerCH.cpp server/CLI.cpp
        server/CLI.h classification/KnnClassifier.cpp classification/KnnClassifier.h
        classification/dist_strategies/EuclideanDistance.cpp classification/dist_strategies/ManhattenDistance.cpp
        classification/dist_strategies/ChebyshevDistance.cpp io/SocketIO.cpp io/StandardIo.cpp)

add_executable(otherClient testClientCopy.cpp
        classification/Reader.cpp classification/Reader.h
        classification/Classifiable.cpp classification/Classifiable.h
        classification/IClassifier.h
        classification/dist_strategies/DistanceCalculator.h
        io/DefaultIO.h io/StandardIO.h io/SocketIO.h
        sockets/TcpServerSocket.h sockets/TcpServerSocket.cpp
        sockets/TcpSocket.h sockets/TcpSocket.cpp
        commands/ICommand.h
        commands/UploadCmd.h commands/UploadCmd.cpp
        commands/UpdateSettingsCmd.cpp commands/UpdateSettingsCmd.h
        classification/dist_strategies/DistCalcFactory.cpp classification/dist_strategies/DistCalcFactory.h
        commands/WriteResultsCmd.cpp commands/WriteResultsCmd.h
        commands/ClassifyCmd.cpp commands/ClassifyCmd.h
        classification/LineToClassifiableConverter.cpp classification/LineToClassifiableConverter.h
        commands/ConfusionMatrixCmd.cpp commands/ConfusionMatrixCmd.h
        server/IClientHandler.h
        server/ClassifyingServerCH.h server/ClassifyingServerCH.cpp server/CLI.cpp
        server/CLI.h classification/KnnClassifier.cpp classification/KnnClassifier.h
        classification/dist_strategies/EuclideanDistance.cpp classification/dist_strategies/ManhattenDistance.cpp
        classification/dist_strategies/ChebyshevDistance.cpp io/SocketIO.cpp io/StandardIo.cpp)

