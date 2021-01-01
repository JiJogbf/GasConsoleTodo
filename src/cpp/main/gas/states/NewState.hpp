#pragma once

#include "..\State.hpp"

#include <string>

class NewState: public State{
public:    
    NewState(int id, const std::string& text);
    char status() override;
};

