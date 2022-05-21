#include "Asteroid.hpp"

const std::string Asteroid::IMAGE_PATH = "images/Asteroid1.png";

Asteroid::Asteroid() : Object(IMAGE_PATH),
                       x(100.f),
                       y(100.f)
{
    sf::Vector2f asteroidCenter(
        static_cast<float>(texture.getSize().x) / 2, static_cast<float>(texture.getSize().y) / 2);
    sprite.setOrigin(asteroidCenter);

    sprite.setScale(3.f, 3.f);
    sprite.setPosition(x, y);
}