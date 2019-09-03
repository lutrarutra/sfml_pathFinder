#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    std::cout << "Hello, World!" << std::endl;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "project_name");

    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent( Event))
        {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.display();
    }
}