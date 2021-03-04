#include "gas\TaskList.hpp"
#include "gas\DefaultTaskList.hpp"
#include "gas\SafeTaskList.hpp"
#include "gas\ObservableTaskList.hpp"
#include "gas\LoggingObs.hpp"
#include <iostream>
#include <fstream>
#include <string>

void display_file(const char* filename){
    // задачи из todo.txt выдать кратким списком 
    // на консоль. по сути можно просто прочитать todo.txt
    // и выдать его на консоль
    std::ifstream stream(filename);
    while(!stream.eof()){
        std::string s;
        std::getline(stream, s);
        std::cout << s << std::endl;
    }
    stream.close();
}

void print_usage(const char* text){
    std::cout << text << std::endl 
        << "usage: todo <action> [parameter]" << std::endl    
        << "commands: " << std::endl
        << "help" << std::endl
        << "new" << std::endl
        << "done" << std::endl
        << "renew" << std::endl
        << "delay" << std::endl
        << "list" << std::endl;
}

int main(int argc, char** argv){
    if(argc > 1){
        std::string action = argv[1];
        if(action == "help"){
            // @todo: сделать так чтобы эта команда спрашивала 
            // у самого списка имена доступных команд. Так же было 
            // бы круто чтобы каждая команда возвращала собственное 
            // описание, что она делает.
            print_usage("Available commands");
        }else if(action == "list"){
            display_file("todo.txt");
        }else if(argc > 2){
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
            print_usage("No action passed");
        }
    }else{
        print_usage("No action passed");
    }
    return 0;
}
