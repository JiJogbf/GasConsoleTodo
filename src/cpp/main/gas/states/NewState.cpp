#include "NewState.hpp"

NewState::NewState(int id, const std::string& text): 
    State(id, text)
{}

char NewState::status(){
    return ' ';
}    