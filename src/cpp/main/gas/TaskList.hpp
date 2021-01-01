#pragma once 

#include "Drawable.hpp"

class TaskList: public Drawable{
public:
    virtual int newTask(const char* text) = 0;
    virtual void done(int id) = 0;
    virtual void renew(int id) = 0;
    virtual void delay(int id) = 0;
    // @todo: #5 adding fileexistance checking 
    virtual void load(const char* filename) = 0;
    virtual void save(const char* filename) = 0;
};
