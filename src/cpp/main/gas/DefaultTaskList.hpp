#pragma once

#include "TaskList.hpp"

#include <map>
#include <string>
#include <memory>

class Task;

using TaskList_Map = std::map<int, std::shared_ptr<Task>>;

class DefaultTaskList: public TaskList{
    TaskList_Map mItems;
    std::string mName;
    int mLastId;
public:
    DefaultTaskList(const char* name);
    ~DefaultTaskList();
    void draw() override;
    int newTask(const char* text) override;
    void done(int id) override;
    void renew(int id) override;
    void delay(int id) override; 
    // @todo: #5 adding fileexistance checking 
    void load(const char* filename) override;
    void save(const char* filename) override;
};

