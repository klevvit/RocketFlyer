#include "Rocket.hpp"
#include "consts.hpp"

Rocket::Rocket() : speedX(10.f), speedY(-30.f), time(std::chrono::steady_clock::now()) {

    texture.loadFromFile(IMAGE_PATH);
    sprite.setTexture(texture);

    x = static_cast<float>(consts::WINDOW_WIDTH) / 2;
    y = static_cast<float>(consts::WINDOW_HEIGHT) - 100.f;

    sf::Vector2f rocketCenter(
        static_cast<float>(texture.getSize().x) / 2,
        static_cast<float>(texture.getSize().y) / 2
    );
    sprite.setOrigin(rocketCenter);

    sprite.setPosition(x, y);
    sprite.setScale(sf::Vector2f(3.f, 3.f));
}

void Rocket::updatePosition() {

    using namespace std::chrono;

    auto new_time = steady_clock::now();
    float dt = duration<float>(new_time - time).count();
    time = new_time;

    x += speedX * dt;
    y += speedY * dt;

    sprite.setPosition(x, y);
}

void Rocket::draw(sf::RenderWindow &window) {

    window.draw(sprite);
}