#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <memory>

// @todo: #2 move all classes to separated moduile's

struct Drawable{
    virtual ~Drawable() = 0;
    virtual void draw() = 0;
};

class State: public Drawable{
protected:
    int mId;
    std::string mText;
    State(int id, const std::string& text): mId(id), mText(text){}
public:
    virtual char status() = 0;
    virtual void draw() override{
        std::cout << "[" << status() << "] #" << mId << " " << mText << std::endl;
    }
};

class DoneState: public State{
public:
    DoneState(int id, const std::string& text): State(id, text){}
    char status() override {return 'x';}
};

class NewState: public State{
public:    
    NewState(int id, const std::string& text): State(id, text){}
    char status() override {return ' ';}    
};

class DelayedState: public State{
public:    
    DelayedState(int id, const std::string& text): State(id, text){}
    char status() override {return '-';}    
};

class Task: public Drawable{
    int mId;
    std::string mText;
    State* mState;
    void changeState(State* state);
public:
    Task(const int id, const char* text, State* state);
    ~Task() override;
    int id()const{ return mId; }
    void draw() override;   
    void done();
    void renew();
    void delay();
    void load(std::ifstream& stream);
    void save(std::ofstream& stream);
};


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


Drawable::~Drawable(){}


Task::Task(const int id, const char* text, State* state): 
    mId(id), mText(text), mState(state)
{}

Task::~Task(){
    delete mState;
}

void Task::draw(){
    mState->draw();
}

void Task::changeState(State* state){
    // @todo #1 create functions for simple nullptr checking and comparing pointers
    if((mState != state) && (state != nullptr)){
        delete mState;
        mState = state;
    }
}

void Task::done(){
    changeState(new DoneState(mId, mText));
}

void Task::renew(){
    changeState(new NewState(mId, mText));
}

void Task::delay(){
    changeState(new DelayedState(mId, mText));
}


void Task::load(std::ifstream& stream){
    std::string buffer = "";
    std::getline(stream, buffer);
    int idPos = buffer.find("#") + 1;

    mId = 0;
    mText = "";

    std::stringstream ss(buffer);
    ss.seekg(idPos);
    ss >> mId;

    int pos = ss.tellg();
    mText = buffer.substr(pos + 1);  
    switch(buffer[1]){
        case 'x':
            done();
            break;
        case '-':
            delay();
            break;
        case ' ':
            renew();
            break;
    }
}

void Task::save(std::ofstream& stream){
    stream << "[" << mState->status() << "] #" << mId << " " << mText << std::endl;
}

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
        Task* t = new Task(id,"", new NewState(id, ""));
        t->load(stream);
        if(id < t->id()){
            mLastId = t->id();
        }
        mItems[id] = std::shared_ptr<Task>(t);
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
    TaskList list("empty_list");
    std::cout << "Console Todo app" << std::endl;
    list.load("test/todo.txt");
    int id = list.newTask("testing some shit");
    list.done(id);
    list.save("test/new_todo.txt");
    return 0;
}
