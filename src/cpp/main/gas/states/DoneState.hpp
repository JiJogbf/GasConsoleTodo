#pragma once

#include "..\State.hpp"

#include <string>

class DoneState: public State{
public:
    DoneState(int id, const std::string& text);
    char status() override;
};

