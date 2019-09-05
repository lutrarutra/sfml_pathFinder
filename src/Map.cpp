//
// Created by lutrarutra on 04/09/2019.
//

#include <stdlib.h>

#include "Map.h"

Map::Map(int stepSize, int mapSize, int margin)
{
    this->stepSize = stepSize;
    this->mapSize = mapSize;
    this->margin = margin;

    start = sf::Vector2i(0, 0);
    end  = sf::Vector2i(mapSize-1, mapSize-1);

    this->rectangles.reserve(mapSize * mapSize);
    this->occupants.reserve(mapSize * mapSize);
    for(int i = 0; i < mapSize; ++i)
    {
        for(int j = 0; j < mapSize; ++j)
        {
            rectangles.push_back(new sf::RectangleShape(sf::Vector2f(stepSize, stepSize)));
        }
    }
    initMap();

}

Map::~Map()
{
    for(int i = 0; i < mapSize; ++i)
    {
        for(int j = 0; j < mapSize; ++j)
        {
            delete(rectangles.at(i * mapSize + j));
        }
    }
}

void Map::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < mapSize; ++i)
    {
        for(int j = 0; j < mapSize; ++j)
        {
            window.draw(sf::RectangleShape(*rectangles.at(i * mapSize + j)));
        }
    }
}

bool Map::isWall(int x, int y)
{
    if(x > mapSize - 1 || y > mapSize - 1 || y < 0 || x < 0)
        return 1;
    return occupants.at(x * mapSize + y) == 0;
}

void Map::addPath(std::vector<sf::Vector3i> &path)
{
    for(auto step : path)
    {
        int i = step.x;
        int j = step.y;
        occupants.at(i * mapSize + j) = 2;
        rectangles.at(i * mapSize + j)->setFillColor(sf::Color::Red);
    }
}

void Map::generateRandomMap()
{
    srand( 3 );
    for(int i = 0; i < mapSize; ++i)
    {
        for(int j = 0; j < mapSize; ++j)
        {
            int r = rand() % 4;
            rectangles.at(i * mapSize + j)->setPosition(sf::Vector2f(i * stepSize + margin, j * stepSize + margin));
            int safeArea = 2;
            if(r == 0 && !(( i < safeArea && j < safeArea) || (i > mapSize - safeArea && j > mapSize - safeArea)))
            {
                rectangles.at(i * mapSize + j)->setFillColor(sf::Color::Black);
                occupants.at(i * mapSize + j) = 0;
            }
        }
    }
}

void Map::putWall(int x, int y)
{
    if(x+1 > mapSize || y+1 > mapSize || x < 0 || y < 0)
        return;
    occupants.at(x * mapSize + y) = 0;
    rectangles.at(x * mapSize + y)->setFillColor(sf::Color::Black);
}

void Map::removeWall(int x, int y)
{
    if(x+1 > mapSize || y+1 > mapSize || x < 0 || y < 0)
        return;
    if(occupants.at(x * mapSize + y) == 0)
    {
        occupants.at(x * mapSize + y) = 1;
        rectangles.at(x * mapSize + y)->setFillColor(sf::Color::White);
    }
}

void Map::removeWalls()
{
    initMap();
}

void Map::initMap()
{
    for(int i = 0; i < mapSize; ++i)
    {
        for(int j = 0; j < mapSize; ++j)
        {
            if(i == start.x && j == start.y)
            {
                rectangles.at(i * mapSize + j)->setFillColor(sf::Color::Green);
                occupants.push_back(3);
            }
            else if(i == end.x && j == end.y)
            {
                rectangles.at(i * mapSize + j)->setFillColor(sf::Color::Blue);
                occupants.push_back(4);
            }
            else
            {
                rectangles.at(i * mapSize + j)->setFillColor(sf::Color::White);
                occupants.push_back(1);
            }
            rectangles.at(i * mapSize + j)->setPosition(sf::Vector2f(i * stepSize + margin, j * stepSize + margin));
            rectangles.at(i * mapSize + j)->setOutlineThickness(1.0f);
            rectangles.at(i * mapSize + j)->setOutlineColor(sf::Color::Black);
        }
    }
}

void Map::setStart(int x, int y)
{
    if(x+1 > mapSize || y+1 > mapSize || x < 0 || y < 0)
        return;
    start = sf::Vector2i(x, y);
    initMap();
}

void Map::setEnd(int x, int y)
{
    if(x+1 > mapSize || y+1 > mapSize || x < 0 || y < 0)
        return;
    end  = sf::Vector2i(x, y);
    initMap();
}

sf::Vector2i Map::getStart() const
{
    return start;
}

sf::Vector2i Map::getEnd() const
{
    return end;
}
