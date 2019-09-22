#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Map.h"

void findNeighbors(sf::Vector3i current, std::vector<sf::Vector3i> &temp, Map &map)
{
    temp.erase(temp.begin(), temp.end());
    if (!map.isWall(current.x, current.y - 1))
        temp.emplace_back(current.x, current.y - 1, 1);
    if (!map.isWall(current.x + 1, current.y))
        temp.emplace_back(current.x + 1, current.y, 1);
    if (!map.isWall(current.x, current.y + 1))
        temp.emplace_back(current.x, current.y + 1, 1);
    if (!map.isWall(current.x - 1, current.y))
        temp.emplace_back(current.x - 1, current.y, 1);
}

void dijkstrasAlgorithm(sf::Vector3i &current, std::vector<bool> &visited, std::vector<sf::Vector3i> &path, Map &map)
{
    std::vector<sf::Vector3i> temp;
    findNeighbors(current, temp, map);
    for (auto neighbor : temp)
    {
    }
}

bool isUsedCoord(int x, int y, std::vector<sf::Vector2i> &coords)
{
    for (int i = 0; i < coords.size(); ++i)
    {
        if (coords.at(i).x == x && coords.at(i).y == y)
            return true;
    }
    return false;
}

void checkCoord(Map &map, int x, int y, int z, std::vector<sf::Vector2i> &usedCoords, std::vector<sf::Vector3i> &lastStep, std::vector<sf::Vector3i> &path)
{
    if (!map.isWall(x, y) && !isUsedCoord(x, y, usedCoords))
    {
        lastStep.emplace_back(x, y, z);
        usedCoords.emplace_back(x, y);
    }
}

void findPath(std::vector<sf::Vector3i> &path, Map &map)
{
    std::vector<sf::Vector3i> lastStep;
    std::vector<sf::Vector2i> usedCoords;
    usedCoords.emplace_back(path.at(0).x, path.at(0).y);
    lastStep.push_back(path.at(0));

    int counter = 0;
    while (counter < 2000)
    {
        int size = lastStep.size();
        for (int i = 0; i < size; ++i)
        {
            auto step = lastStep.at(i);
            checkCoord(map, step.x, step.y - 1, path.size() - size + 1 + i, usedCoords, lastStep, path);
            checkCoord(map, step.x + 1, step.y, path.size() - size + 1 + i, usedCoords, lastStep, path);
            checkCoord(map, step.x, step.y + 1, path.size() - size + 1 + i, usedCoords, lastStep, path);
            checkCoord(map, step.x - 1, step.y, path.size() - size + 1 + i, usedCoords, lastStep, path);
            checkCoord(map, step.x + 1, step.y - 1, path.size() - size + 1 + i, usedCoords, lastStep, path);
            checkCoord(map, step.x + 1, step.y + 1, path.size() - size + 1 + i, usedCoords, lastStep, path);
            checkCoord(map, step.x - 1, step.y + 1, path.size() - size + 1 + i, usedCoords, lastStep, path);
            checkCoord(map, step.x - 1, step.y - 1, path.size() - size + 1 + i, usedCoords, lastStep, path);
        }

        lastStep.erase(lastStep.begin(), lastStep.begin() + size);
        for (auto step : lastStep)
        {
            path.push_back(step);
            if (step.x == map.getStart().x && step.y == map.getStart().y)
            {
                std::cout << "Finished" << std::endl;
                return;
            }
        }
        ++counter;
    }
}

void clearPaths(std::vector<sf::Vector3i> &path, Map &map)
{
    std::vector<sf::Vector3i> temp;
    sf::Vector3i start;
    for (auto step : path)
    {
        if (step.x == map.getStart().x && step.y == map.getStart().y)
        {
            start = step;
        }
    }
    temp.push_back(start);
    int i = start.z;
    while (i > 0)
    {
        //std::cout << path.at(i - 1).x << " " << path.at(i - 1).y << std::endl;
        temp.push_back(path.at(i - 1));
        i = path.at(i - 1).z;
    }
    path.erase(path.begin(), path.end());
    for (auto step : temp)
    {
        path.push_back(step);
    }
}

int main()
{
    sf::Font font;
    if (!font.loadFromFile("OpenSans-Regular.ttf"))
    {
        std::cout << "Could not load font.." << std::endl;
        return 0;
    }

    sf::RenderWindow window(sf::VideoMode(1280, 1280), "project_name", sf::Style::Close);

    sf::Text text;
    text.setFont(font);
    text.setString("'C' - Clear map, 'S' - Start position, 'E' - End position, 'R' - Random map, 'B' - Begin pathing.");
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(24);

    int mapSize = 50;
    int margin = 50;
    Map map((1280 - margin * 2) / mapSize, mapSize, margin);

    std::vector<sf::Vector3i> path;

    bool pathDone = false;

    while (window.isOpen())
    {
        sf::Event Event;

        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                window.close();

            if (Event.type == sf::Event::KeyPressed && !pathDone)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                {
                    map.removeWalls();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                {
                    map.generateRandomMap();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    int mx = sf::Mouse::getPosition(window).x - margin;
                    int my = sf::Mouse::getPosition(window).y - margin;
                    if (!(mx < 0 || my < 0 || mx > 1280 - margin || my > 1280 - margin))
                    {
                        int x = mx / ((1280 - 2 * margin) / mapSize);
                        int y = my / ((1280 - 2 * margin) / mapSize);
                        map.setStart(x, y);
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                {
                    int mx = sf::Mouse::getPosition(window).x - margin;
                    int my = sf::Mouse::getPosition(window).y - margin;
                    if (!(mx < 0 || my < 0 || mx > 1280 - margin || my > 1280 - margin))
                    {
                        int x = mx / ((1280 - 2 * margin) / mapSize);
                        int y = my / ((1280 - 2 * margin) / mapSize);
                        map.setEnd(x, y);
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                {
                    //starting coords of our algorithm
                    path.emplace_back(map.getEnd().x, map.getEnd().y, 0);
                    findPath(path, map);
                    clearPaths(path, map);
                    map.addPath(path);
                    pathDone = true;
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                int mx = sf::Mouse::getPosition(window).x - margin;
                int my = sf::Mouse::getPosition(window).y - margin;
                if (!(mx < 0 || my < 0 || mx > 1280 - margin || my > 1280 - margin))
                {
                    int x = mx / ((1280 - 2 * margin) / mapSize);
                    int y = my / ((1280 - 2 * margin) / mapSize);
                    map.putWall(x, y);
                }
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                int mx = sf::Mouse::getPosition(window).x - margin;
                int my = sf::Mouse::getPosition(window).y - margin;
                if (!(mx < 0 || my < 0 || mx > 1280 - margin || my > 1280 - margin))
                {
                    int x = mx / ((1280 - 2 * margin) / mapSize);
                    int y = my / ((1280 - 2 * margin) / mapSize);
                    map.removeWall(x, y);
                }
            }
        }

        window.clear(sf::Color::White);
        map.draw(window);
        if (!pathDone)
            window.draw(text);
        window.display();
    }
}