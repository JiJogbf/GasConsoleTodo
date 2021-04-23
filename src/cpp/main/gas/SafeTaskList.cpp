#include "SafeTaskList.hpp"

#include <fstream>

static bool fileExists(const char* filename){
    std::ifstream stream(filename);
    return stream.good();
}

SafeTaskList::SafeTaskList(TaskList* list): TaskListDecorator(list){}

void SafeTaskList::load(const char* filename){
    // @todo: if file not exists
    // we simple create empty document
    if(fileExists(filename)){
        TaskListDecorator::load(filename);
    } 
}