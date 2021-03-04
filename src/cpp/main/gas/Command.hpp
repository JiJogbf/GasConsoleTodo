#pragma once

namespace gas{
    struct command{
        virtual ~command() = 0;
        virtual void execute() = 0;
    };
}


