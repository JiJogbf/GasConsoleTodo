#pragma once 

#include "TaskList.hpp"

struct Observer{
    virtual ~Observer() = 0;
    virtual void onAction(TaskList* list, int id) = 0;
    virtual void onUpdate(TaskList* list) = 0;
};