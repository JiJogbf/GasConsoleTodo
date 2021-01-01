#include "TaskList.hpp"

#include "Task.hpp"
#include "states\NewState.hpp"

#include <iostream>

TaskList::TaskList(const char* name):
    mItems(), mName(name), mLastId(0)
{}

TaskList::~TaskList(){}

void TaskList::draw(){
    std::cout << mName << std::endl;
    for(auto it = mItems.begin(); it != mItems.end(); ++it){
        it->second->draw();
    }
}

int TaskList::newTask(const char* text){
    int newId = ++mLastId;
    Task* task = new Task(newId, text, new NewState(newId, text));
    mItems[newId] = std::shared_ptr<Task>(task);
    return newId;
}

void TaskList::done(int id){
    auto findResult = mItems.find(id);
    if(findResult != mItems.end()){
        mItems[id]->done();
    }
}

void TaskList::renew(int id){
    auto findResult = mItems.find(id);
    if(findResult != mItems.end()){
        mItems[id]->renew();
    }
}

void TaskList::delay(int id){
    auto findResult = mItems.find(id);
    if(findResult != mItems.end()){
        mItems[id]->delay();
    }
}

void TaskList::load(const char* filename){
    mLastId = 0;
    std::ifstream stream(filename);
    while(!stream.eof()){
        int id = mLastId++;
        Task* t = new Task(id, "", new NewState(id, ""));
        t->load(stream);
        int loadedid = t->id();
        if(id < loadedid){
            mLastId = loadedid;
        }
        
        if(loadedid > 0){
            mItems[loadedid] = std::shared_ptr<Task>(t);
        }else{
            delete t;
        }
    }
    stream.close();
}

void TaskList::save(const char* filename){
    std::ofstream stream(filename);
    for(auto it = mItems.begin(); it != mItems.end(); ++it){
        it->second->save(stream);
    }
    stream.close();
}