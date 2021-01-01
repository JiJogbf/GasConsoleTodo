#include "DoneState.hpp"

DoneState::DoneState(int id, const std::string& text): State(id, text){}
char DoneState::status() {
    return 'x';
}