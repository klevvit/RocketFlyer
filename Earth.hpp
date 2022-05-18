#pragma once

#include "Object.hpp"

class Earth : public Object
{

public:
    Earth();

private:
    static const std::string IMAGE_PATH;

    float y;

};