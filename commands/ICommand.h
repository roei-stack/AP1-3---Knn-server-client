//
// Created by user on 9/24/2021.
//

#ifndef HW3_ICOMMAND_H
#define HW3_ICOMMAND_H

#include <string>
using std::string;

class ICommand {
    virtual string description() = 0;
    virtual void execute() = 0;
};


#endif //HW3_ICOMMAND_H
