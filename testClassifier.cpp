#include <iostream>
#include "classification/Reader.h"
#include "classification/IClassifier.h"
#include "classification/KnnClassifier.h"
#include "sockets/TcpSocket.h"
#include "sockets/TcpServerSocket.h"
#include "io/SocketIO.h"

using std::string;

int main() {


    /*
    string msg = "trolololol";
    TcpServerSocket serverSocket(3257, "127.0.0.1");
    TcpSocket client("127.0.0.1", 3257);

    TcpSocket* serverClientSocket = serverSocket.accept();
    SocketIO socketIo(&client);
    socketIo.write(msg);
    cout << serverClientSocket->receive() << endl << "********************" << endl;
     */


    string classifiedPath = "../classification/Iris_train.csv";
    string unclassifiedPath = "../classification/Iris_test.csv";
    //// initializing the reader for classified and unclassified
    Reader reader(classifiedPath);
    Reader otherReader(unclassifiedPath);
    //// loading the datasets
    vector<Classifiable*>* classifiedData = reader.buildDataset();
    vector<Classifiable*>* unclassifiedData = otherReader.buildDataset();
    // applying classifier
    EuclideanDistance calculator;


    // creating classifier, classifying all and getting results
    KnnClassifier classifier(5, "EUC", reinterpret_cast<vector<struct Classifiable *> *>(classifiedData),
                             reinterpret_cast<vector<struct Classifiable *> *>(unclassifiedData));

    classifier.classifyAllTestingData();
    vector<string>* ans = classifier.getResults();

    // printing results
    for (int i = 0; i < ans->size(); i++) {
        std::cout << "PREDICTED : " << ans->at(i) << " ************ TRUE CLASS : " << unclassifiedData->at(i)->getClassification() << std::endl;
    }


    // PRINTING THE CONFUSION MATRIX
    std::vector<std::pair<string,std::vector<double>>> mat = classifier.calculateConfusionMatrix();
    // TOP LINE
    std::cout << "\t";
    for (auto &className : mat) {
        std::cout << "\t" << className.first;
    }
    std::cout <<std::endl;
    // REST OF THE MATRIX
    for (auto& i : mat) {
        std::cout << i.first;
        for (double x : i.second) {
            std::cout << "\t" << x << "%";
        }
        std::cout << std::endl;
    }

    return 0;
}
