#pragma once 

#include "TaskList.hpp"

#include "command.hpp"

namespace gas{
    class help_command: public command{
    private:
        TaskList* list;
    public:
        help_command(TaskList* list);
        ~help_command();
        void execute() override;
    };
}