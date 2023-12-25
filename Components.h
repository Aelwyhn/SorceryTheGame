#pragma once

#include "EntityComponentSystem.h"

class PositionComponent : public Component
{
private:
    int x;
    int y;

public:
    
    int getX() { return x; }
    int getY() { return y; }

    void setXY(int x, int y)
    { 
        this->x = x;
        this->y = y;
    }

    void init() override
    {
        x = 0;
        y = 0;
    }

    void update() override
    {
        x++;
        y++;
    }
};