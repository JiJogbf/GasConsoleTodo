#pragma once

#include "..\State.hpp"

#include <string>

class DelayedState: public State{
public:    
    DelayedState(int id, const std::string& text);
    char status() override;
};
