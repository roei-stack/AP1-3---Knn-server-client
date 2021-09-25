//
// Created by user on 9/25/2021.
//

#include "ClassifyCmd.h"

void ClassifyCmd::execute() {
    this->classifier->classifyAllTestingData();
    this->dio->write("classifying data complete");
}
