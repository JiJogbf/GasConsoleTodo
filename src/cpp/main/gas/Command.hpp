#pragma once

struct Command{
    virtual ~Command() = 0;
    virtual void execute() = 0;
};

