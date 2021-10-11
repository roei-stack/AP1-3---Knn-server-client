cmake_minimum_required(VERSION 3.16)
project(hw3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(server/classification server/classification/dist_strategies server/cli server/cli/commands server
        sockets io)

add_executable(server server/serverMain.cpp
        server/classification/Classifiable.cpp server/classification/Classifiable.h
        server/cli/commands/DownloadCmd.h server/cli/commands/DownloadCmd.cpp
        server/classification/IClassifier.h
        server/classification/dist_strategies/DistanceCalculator.h
        io/DefaultIO.h io/StandardIO.h io/SocketIO.h
        sockets/TcpServerSocket.h sockets/TcpServerSocket.cpp
        sockets/TcpSocket.h sockets/TcpSocket.cpp
        server/cli/commands/ICommand.h
        server/cli/commands/UploadCmd.h server/cli/commands/UploadCmd.cpp
        server/cli/commands/UpdateSettingsCmd.cpp server/cli/commands/UpdateSettingsCmd.h
        server/classification/dist_strategies/DistCalcFactory.cpp server/classification/dist_strategies/DistCalcFactory.h
        server/cli/commands/WriteResultsCmd.cpp server/cli/commands/WriteResultsCmd.h
        server/cli/commands/ClassifyCmd.cpp server/cli/commands/ClassifyCmd.h
        server/cli/commands/LineToClassifiableConverter.cpp  server/cli/commands/LineToClassifiableConverter.h
        server/cli/commands/ConfusionMatrixCmd.cpp server/cli/commands/ConfusionMatrixCmd.h
        server/cli/CLI.cpp
        server/cli/CLI.h server/classification/KnnClassifier.cpp server/classification/KnnClassifier.h
        server/classification/dist_strategies/EuclideanDistance.cpp server/classification/dist_strategies/ManhattenDistance.cpp
        server/classification/dist_strategies/ChebyshevDistance.cpp io/SocketIO.cpp io/StandardIo.cpp)

add_executable(testClient clientMain.cpp
        io/DefaultIO.h io/StandardIO.h io/StandardIo.cpp io/SocketIO.h io/SocketIO.cpp
        sockets/TcpSocket.h sockets/TcpSocket.cpp)

