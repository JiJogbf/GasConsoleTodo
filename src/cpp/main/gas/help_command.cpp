#include "help_command.hpp"

#include <iostream>

namespace gas{

HelpCommand::HelpCommand(TaskList* list): list(list){}

HelpCommand::~HelpCommand(){
    list = nullptr;
}

void HelpCommand::execute(){
    std::cout << "commands: " << std::endl
        << "help" << std::endl
        << "new" << std::endl
        << "done" << std::endl
        << "renew" << std::endl
        << "delay" << std::endl
        << "list" << std::endl;
}

}