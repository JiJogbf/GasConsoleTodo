#include "LoggingObs.hpp"

#include <iostream>

LoggingObs::LoggingObs(){
    std::cout << "list creating" << std::endl;
}
    
LoggingObs::~LoggingObs(){
    std::cout << "list destroying" << std::endl;
}
    
void LoggingObs::onAction(TaskList* list, int id){
    std::cout << "perorming action with task id = "<< id << std::endl;
}

void LoggingObs::onUpdate(TaskList* list){
    std::cout << "list performed content update" << std::endl;
}
