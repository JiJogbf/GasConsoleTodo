#include "gas\TaskList.hpp"
#include "gas\DefaultTaskList.hpp"
#include "gas\SafeTaskList.hpp"
#include "gas\ObservableTaskList.hpp"
#include "gas\LoggingObs.hpp"

#include <iostream>
#include <string>

void printUsage(const char* text){
    std::cout << text << std::endl 
        << "usage: todo <action> [parameter]" << std::endl    
        << "commands: " << std::endl
        << "new" << std::endl
        << "done" << std::endl;
}

int main(int argc, char** argv){
    if(argc > 1){
        std::string action = argv[1];
        if(argc > 2){
            std::string param = argv[2];
            ObservableTaskList* obsList = new ObservableTaskList(
                    new SafeTaskList(
                        new DefaultTaskList("todo-list")
                    )
                );
            obsList->attach(new LoggingObs());
            TaskList* list = obsList;

            list->load("todo.txt");
            if(action == "new"){
                list->newTask(param.c_str());
            }else if(action == "done"){
                int id = std::stoi(param);
                list->done(id);
            }else if(action == "renew"){
                int id = std::stoi(param);
                list->renew(id);
            }else if(action == "delay"){
                int id = std::stoi(param);
                list->delay(id);            
            }else{
                std::cout << "unrecognized action: '" << action << "'" << std::endl;
            }
            list->save("todo.txt");            
            delete list;
        }else{
            printUsage("No action passed");
        }
    }else{
        printUsage("No action passed");
    }
    return 0;
}
