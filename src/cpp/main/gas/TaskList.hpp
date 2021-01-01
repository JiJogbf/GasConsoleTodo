#pragma once

#include "Drawable.hpp"

#include <map>
#include <string>
#include <memory>

class Task;

using TaskList_Map = std::map<int, std::shared_ptr<Task>>;

class TaskList: public Drawable{
    TaskList_Map mItems;
    std::string mName;
    int mLastId;
public:
    TaskList(const char* name);
    ~TaskList();
    void draw() override;
    int newTask(const char* text);
    void done(int id);
    void renew(int id);
    void delay(int id);
    void load(const char* filename);
    void save(const char* filename);
};

