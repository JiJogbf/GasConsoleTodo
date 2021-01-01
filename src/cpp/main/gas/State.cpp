#include "State.hpp"

#include <iostream>

State::State(int id, const std::string& text): mId(id), mText(text){}

void State::draw(){
    std::cout << "[" << status() << "] #" << mId << " " << mText << std::endl;
}