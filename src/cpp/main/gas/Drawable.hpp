#pragma once

struct Drawable{
    virtual ~Drawable() = 0;
    virtual void draw() = 0;
};