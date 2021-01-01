#pragma once 

#include "TaskList.hpp"

class TaskListDecorator: public TaskList{
protected:
    TaskList* mOrigin;
public:
    TaskListDecorator(TaskList* origin);
    virtual ~TaskListDecorator();
    int newTask(const char* text);
    void done(int id);
    void renew(int id);
    void delay(int id);
    // @todo: #5 adding fileexistance checking 
    void load(const char* filename);
    void save(const char* filename);
};
