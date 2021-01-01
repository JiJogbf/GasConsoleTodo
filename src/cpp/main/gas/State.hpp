#pragma once

#include "Drawable.hpp"

#include <string>

class State: public Drawable{
protected:
    int mId;
    std::string mText;
    State(int id, const std::string& text);
public:
    virtual char status() = 0;
    virtual void draw();
};
