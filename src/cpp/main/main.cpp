#include "gas\Command.hpp"
#include "gas\Drawable.hpp"
#include "gas\State.hpp"
#include "gas\states\NewState.hpp"
#include "gas\Task.hpp"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <memory>

// @todo: #2 move all classes to separated moduile's

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


int main(int argc, char** argv){
    if(argc > 1){
        std::string action = argv[1];
        if(argc > 2){
            std::string param = argv[2];
            TaskList list("todo_list");
            list.load("todo.txt");
            
            if(action == "new"){
                list.newTask(param.c_str());
            }else if(action == "done"){
                int id = std::stoi(param);
                list.done(id);
            }else if(action == "renew"){
                int id = std::stoi(param);
                list.renew(id);
            }else if(action == "delay"){
                int id = std::stoi(param);
                list.delay(id);            
            }else{
                std::cout << "unrecognized action: '" << action << "'" << std::endl;
            }
            list.save("todo.txt");            
        }else{
            std::cout << "Not enough params" << std::endl 
                << "usage: todo <action> [parameter]" << std::endl    
                << "commands: " << std::endl
                << "new" << std::endl
                << "done" << std::endl;
        }
    }else{
        std::cout 
            << "No action passed" << std::endl 
            << "usage: todo <action> [parameter]" << std::endl    
            << "commands: " << std::endl
            << "new" << std::endl
            << "done" << std::endl;
    }
    return 0;
}
