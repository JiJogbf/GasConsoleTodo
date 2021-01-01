#pragma once 

#include "TaskListDecorator.hpp"

class SafeTaskList: public TaskListDecorator{
public:
    void load(const char* filename) override;
};