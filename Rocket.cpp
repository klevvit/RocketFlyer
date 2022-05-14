#include "Rocket.hpp"
#include "consts.hpp"

Rocket::Rocket() {

    texture.loadFromFile(IMAGE_PATH);
    sprite.setTexture(texture);

    sf::Vector2f rocketCenter(
        static_cast<float>(texture.getSize().x) / 2,
        static_cast<float>(texture.getSize().y) / 2
    );

    sprite.setOrigin(rocketCenter);
    sprite.setPosition(sf::Vector2f(static_cast<float>(consts::WINDOW_WIDTH) / 2, static_cast<float>(consts::WINDOW_HEIGHT) - 100.f));
    sprite.setScale(sf::Vector2f(3.f, 3.f));
}

void Rocket::draw(sf::RenderWindow& window) {

    window.draw(sprite);
}