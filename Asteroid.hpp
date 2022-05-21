#pragma once

#include "Object.hpp"

class Asteroid : public Object
{
public:
    Asteroid();

private:
    static const std::string IMAGE_PATH;

    float x;
    float y;
};