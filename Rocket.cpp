#include "Rocket.hpp"
#include "consts.hpp"

const std::string Rocket::IMAGE_PATH = "images/Rocket.png";


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

std::map<char, bool> Rocket::getKeysState() {

    std::map<char, bool> ans;

    for (const auto& [c, keys] : KEYMAP) {

        if(std::any_of(keys.begin(), keys.end(), [](const auto& key) { return sf::Keyboard::isKeyPressed(key); })) {
            
            ans[c] = true;
        } else {
            ans[c] = false;
        }
    }

    return ans;
}

void Rocket::updatePosition() {

    auto new_time = std::chrono::steady_clock::now();
    float dt = std::chrono::duration<float>(new_time - time).count();
    time = new_time;

    auto keysState = getKeysState();

    if (keysState['L'] && !keysState['R']) {
        
        // accelerate left
        speedX -= a * dt;

    } else if (!keysState['L'] && keysState['R']) {
        
        // accelerate right
        speedX += a * dt;
    }
    if (keysState['U'] && !keysState['D']) {

        // accelerate up
        speedY -= a * dt;

    } else if (!keysState['U'] && keysState['D']) {

        // accelerate down
        speedY += a * dt;
    }

    x += speedX * dt;
    y += speedY * dt;

    sprite.setPosition(x, y);
}

void Rocket::draw(sf::RenderWindow &window) {

    window.draw(sprite);
}