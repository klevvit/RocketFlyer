#include "Sky.hpp"
#include "consts.hpp"

const std::string Sky::IMAGE_PATH = "images/Sky.png";

Sky::Sky() : Object(IMAGE_PATH)
{
    texture.setRepeated(true);
    sprite.setScale(3.0f, 3.0f);
    sprite.setPosition(0.f, -1000.f * static_cast<float>(consts::WINDOW_WIDTH));  // todo make better moving rendering
    sprite.setTextureRect(sf::IntRect(0, 0, 200 * consts::WINDOW_WIDTH, 200 * consts::WINDOW_HEIGHT));
}