#include "TaskListDecorator.hpp"

TaskListDecorator::TaskListDecorator(TaskList* origin): TaskList(), mOrigin(origin){}

TaskListDecorator::~TaskListDecorator(){
    delete mOrigin;
}

int TaskListDecorator::newTask(const char* text){
    return mOrigin->newTask(text);
}

void TaskListDecorator::done(int id){
    mOrigin->done(id);
}

void TaskListDecorator::renew(int id){
    mOrigin->renew(id);
}

void TaskListDecorator::delay(int id){
    mOrigin->delay(id);
}

// @todo: #5 adding fileexistance checking 
void TaskListDecorator::load(const char* filename){
    mOrigin->load(filename);
}

void TaskListDecorator::save(const char* filename){
    mOrigin->save(filename);
}
