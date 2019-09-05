//
// Created by lutrarutra on 04/09/2019.
//

#ifndef SFML_PATHFINDER_MAP_H
#define SFML_PATHFINDER_MAP_H

#include <vector>
#include <SFML/Graphics.hpp>

class Map {
public:
    Map(int stepSize, int mapSize, int margin);
    ~Map();
    bool isWall(int x, int y);
    void addPath(std::vector<sf::Vector3i> &path);
    void draw(sf::RenderWindow &window);
    void generateRandomMap();
    void putWall(int x, int y);
    void removeWall(int x, int y);
    void removeWalls();
    void setStart(int x, int y);
    void setEnd(int x, int y);
    sf::Vector2i getStart() const;
    sf::Vector2i getEnd() const;

private:
    int stepSize, mapSize, margin;
    sf::Vector2i start;
    sf::Vector2i end;

    std::vector<sf::RectangleShape*> rectangles;
    void initMap();
    // 0 - wall, 1 - none, 2 - path, 3 - start, 4 - end
    std::vector<int> occupants;
};


#endif //SFML_PATHFINDER_MAP_H
