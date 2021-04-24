#pragma once 

#include "TaskList.hpp"

#include "command.hpp"

namespace gas{
    class HelpCommand: public Command{
    private:
        TaskList* list;
    public:
        HelpCommand(TaskList* list);
        ~HelpCommand();
        void execute() override;
    };
}