#include <iostream>

struct Drawable{
    virtual ~Drawable() = 0;
    virtual void draw() = 0;
};

Drawable::~Drawable(){}

int main(){
    std::cout << "Console Todo app" << std::endl;
    return 0;
}