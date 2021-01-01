#include "DelayedState.hpp"

DelayedState::DelayedState(int id, const std::string& text): 
    State(id, text)
{}

char DelayedState::status(){
    return '-';
}    