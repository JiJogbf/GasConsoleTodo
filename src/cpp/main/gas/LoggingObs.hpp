#pragma once

#include "TasKList.hpp"
#include "Observer.hpp"

class LoggingObs: public Observer{
public:
    LoggingObs();    
    ~LoggingObs() override;   
    void onAction(TaskList* list, int id) override;
    void onUpdate(TaskList* list) override;
};