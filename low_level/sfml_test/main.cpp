#include <SFML/Graphics.hpp>

/*
Compile

 g++ main.cpp -o app \
-std=c++17 \
-I/opt/homebrew/opt/sfml/include \
-L/opt/homebrew/opt/sfml/lib \
-lsfml-graphics -lsfml-window -lsfml-system

./app
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Movement");

    sf::RectangleShape player({50.f, 50.f});
    player.setFillColor(sf::Color::Green);
    player.setPosition({375.f, 275.f});

    float speed = 300.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            player.move({-speed * dt, 0});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            player.move({speed * dt, 0});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            player.move({0, -speed * dt});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            player.move({0, speed * dt});

        window.clear();
        window.draw(player);
        window.display();
    }
}



