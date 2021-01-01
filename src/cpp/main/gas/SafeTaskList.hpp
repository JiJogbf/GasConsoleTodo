#pragma once 

#include "TaskListDecorator.hpp"

class SafeTaskList: public TaskListDecorator{
public:
    SafeTaskList(TaskList* list);
    void load(const char* filename) override;
};