#include "DefaultTaskList.hpp"

#include "Task.hpp"
#include "states\NewState.hpp"

#include <iostream>

DefaultTaskList::DefaultTaskList(const char* name): 
    TaskList(), mItems(), mName(name), mLastId(0)
{}

DefaultTaskList::~DefaultTaskList(){}

void DefaultTaskList::draw(){
    std::cout << mName << std::endl;
    for(auto it = mItems.begin(); it != mItems.end(); ++it){
        it->second->draw();
    }
}

int DefaultTaskList::newTask(const char* text){
    int newId = ++mLastId;
    Task* task = new Task(newId, text, new NewState(newId, text));
    mItems[newId] = std::shared_ptr<Task>(task);
    return newId;
}

void DefaultTaskList::done(int id){
    auto findResult = mItems.find(id);
    if(findResult != mItems.end()){
        mItems[id]->done();
    }
}

void DefaultTaskList::renew(int id){
    auto findResult = mItems.find(id);
    if(findResult != mItems.end()){
        mItems[id]->renew();
    }
}

void DefaultTaskList::delay(int id){
    auto findResult = mItems.find(id);
    if(findResult != mItems.end()){
        mItems[id]->delay();
    }
}

void DefaultTaskList::load(const char* filename){
    mLastId = 0;
    std::ifstream stream(filename);
    std::getline(stream, mName);
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

void DefaultTaskList::save(const char* filename){
    std::ofstream stream(filename);
    stream << mName << std::endl;
    for(auto it = mItems.begin(); it != mItems.end(); ++it){
        it->second->save(stream);
    }
    stream.close();
}