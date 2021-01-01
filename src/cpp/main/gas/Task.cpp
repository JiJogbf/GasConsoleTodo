#include "Task.hpp"

#include <sstream>

#include "states\DoneState.hpp"
#include "states\DelayedState.hpp"
#include "states\NewState.hpp"

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