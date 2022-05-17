#include "Rocket.hpp"
#include "consts.hpp"

const std::string Rocket::IMAGE_PATH = "images/Rocket.png";

Rocket::Rocket() : x(static_cast<float>(consts::WINDOW_WIDTH) / 2),
                   y(static_cast<float>(consts::WINDOW_HEIGHT) - 100.f),
                   speedX(0.f),
                   speedY(0.f),
                   a(100.f),
                   yBound(y - 120.f),
                   time(std::chrono::steady_clock::now())
{
    texture.loadFromFile(IMAGE_PATH);
    sprite.setTexture(texture);

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

        // accelerate left
        speedX -= a * dt;
    }
    else if (!keysState['L'] && keysState['R'])
    {

        // accelerate right
        speedX += a * dt;
    }
    if (keysState['U'] && !keysState['D'])
    {

        // accelerate up
        speedY -= a * dt;
    }
    else if (!keysState['U'] && keysState['D'])
    {

        // accelerate down
        speedY += a * dt;
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
}

const sf::Sprite &Rocket::getSprite()
{
    return sprite;
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