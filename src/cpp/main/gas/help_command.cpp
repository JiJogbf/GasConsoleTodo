#include "help_command.hpp"

#include <iostream>

namespace gas{

help_command::help_command(TaskList* list): list(list){}

help_command::~help_command(){
    list = nullptr;
}

void help_command::execute(){
    std::cout << "commands: " << std::endl
        << "help" << std::endl
        << "new" << std::endl
        << "done" << std::endl
        << "renew" << std::endl
        << "delay" << std::endl
        << "list" << std::endl;
}

}