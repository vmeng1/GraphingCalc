#ifndef GRAPH_H
#define GRAPH_H

#include "graph_info.h"
#include "plot.h"
#include "random.h"
#include "constants.h"

#include <iostream>

class Graph
{
public:
    Graph();
    Graph(graph_info* info);
    void set_info();
    void update(graph_info* info); //void step
    void draw(sf::RenderWindow& window);
private:
    graph_info* _info;
    Plot _plotter;

    //vector<Particle> system;
    vector<sf::CircleShape> system;
    vector<sf::RectangleShape> axis;
    vector<sf::Vector2f> points;
    sf::CircleShape shape;
    sf::RectangleShape x;
    sf::RectangleShape y;
    sf::Vector2f vel;


};

#endif