#pragma once

#include "Drawable.hpp"
#include "State.hpp"

#include <string>
#include <fstream>

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
