#include "gas\TaskList.hpp"

#include <iostream>
#include <string>

// @todo: #2 move all classes to separated moduile's

int main(int argc, char** argv){
    if(argc > 1){
        std::string action = argv[1];
        if(argc > 2){
            std::string param = argv[2];
            TaskList list("todo_list");
            list.load("todo.txt");
            
            if(action == "new"){
                list.newTask(param.c_str());
            }else if(action == "done"){
                int id = std::stoi(param);
                list.done(id);
            }else if(action == "renew"){
                int id = std::stoi(param);
                list.renew(id);
            }else if(action == "delay"){
                int id = std::stoi(param);
                list.delay(id);            
            }else{
                std::cout << "unrecognized action: '" << action << "'" << std::endl;
            }
            list.save("todo.txt");            
        }else{
            std::cout << "Not enough params" << std::endl 
                << "usage: todo <action> [parameter]" << std::endl    
                << "commands: " << std::endl
                << "new" << std::endl
                << "done" << std::endl;
        }
    }else{
        std::cout 
            << "No action passed" << std::endl 
            << "usage: todo <action> [parameter]" << std::endl    
            << "commands: " << std::endl
            << "new" << std::endl
            << "done" << std::endl;
    }
    return 0;
}
