#include <cmath>

#include "Rocket.hpp"
#include "consts.hpp"

const std::string Rocket::IMAGE_PATH = "images/Rocket.png";

Rocket::Rocket() : Object(IMAGE_PATH),
                   x(static_cast<float>(consts::WINDOW_WIDTH) / 2),
                   y(static_cast<float>(consts::WINDOW_HEIGHT) - 100.f),
                   speedX(0.f),
                   speedY(0.f),
                   angle(0.f),
                   a(100.f),
                   omega(60.f),
                   yBound(y - 120.f),
                   time(std::chrono::steady_clock::now())
{

    sf::Vector2f rocketCenter(
        static_cast<float>(texture.getSize().x) / 2,
        static_cast<float>(texture.getSize().y) / 2);
    sprite.setOrigin(rocketCenter);

    sprite.setPosition(x, y);
    sprite.setScale(sf::Vector2f(3.f, 3.f));

    view.setSize(consts::WINDOW_WIDTH, consts::WINDOW_HEIGHT);
    view.setCenter(static_cast<float>(consts::WINDOW_WIDTH) / 2, static_cast<float>(consts::WINDOW_HEIGHT) / 2);
}

void Rocket::updatePosition()
{

    auto new_time = std::chrono::steady_clock::now();
    float dt = std::chrono::duration<float>(new_time - time).count();
    time = new_time;

    auto keysState = getKeysState();

    if (keysState['L'] && !keysState['R'])
    {

        // rotate left
        angle -= omega * dt;
    }
    else if (!keysState['L'] && keysState['R'])
    {

        // rotate right
        angle += omega * dt;
    }
    if (keysState['U'])
    {

        // accelerate
        speedY -= a * cos(angle * M_PI / 180.0) * dt;
        speedX += a * sin(angle * M_PI / 180.0) * dt;
    }

    float deltaX = speedX * dt;
    float deltaY = speedY * dt;
    x += deltaX;
    y += deltaY;

    const float screenCenterX = static_cast<float>(consts::WINDOW_WIDTH) / 2;
    const float screenCenterY = static_cast<float>(consts::WINDOW_HEIGHT) / 2;

    if (y > yBound)
    {
        view.setCenter(screenCenterX, screenCenterY);
    }
    else
    {
        view.setCenter(screenCenterX, screenCenterY - yBound + y);
    }

    sprite.setPosition(x, y);
    sprite.setRotation(angle);
}

const sf::View &Rocket::getView()
{
    return view;
}

std::map<char, bool> Rocket::getKeysState()
{

    std::map<char, bool> ans;

    for (const auto &[c, keys] : KEYMAP)
    {

        if (std::any_of(keys.begin(), keys.end(), [](const auto &key)
                        { return sf::Keyboard::isKeyPressed(key); }))
        {

            ans[c] = true;
        }
        else
        {
            ans[c] = false;
        }
    }

    return ans;
}