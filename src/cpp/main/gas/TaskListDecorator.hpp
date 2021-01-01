#pragma once 

#include "TaskList.hpp"

class TaskListDecorator: public TaskList{
protected:
    TaskList* mOrigin;
public:
    TaskListDecorator(TaskList* origin);
    virtual ~TaskListDecorator();
    int newTask(const char* text);
    void done(int id) override;
    void draw() override;
    void renew(int id) override;
    void delay(int id) override;
    // @todo: #5 adding fileexistance checking 
    void load(const char* filename) override;
    void save(const char* filename) override;
};
