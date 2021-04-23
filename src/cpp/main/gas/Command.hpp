#pragma once

namespace gas{
    struct Command{
        virtual ~Command() = 0;
        virtual void execute() = 0;
    };
}


