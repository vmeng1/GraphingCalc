#include "graph.h"

Graph::Graph(){
    _info = nullptr;
    _plotter = Plot();
}
Graph::Graph(graph_info* info){
    _info = info;
    _plotter = Plot(_info);


    _plotter.set_info();
    points = _plotter();
    for (int i = 0; i < points.size(); i++){
        
        shape = sf::CircleShape(2);
        shape.setPosition(points[i]);
        if(_info->polar){
            shape.setFillColor(sf::Color::Magenta);
        }
        system.push_back(shape);
        
    
    }

   
    x.setSize(sf::Vector2f(_info->_xaxis, _info->_yaxis));
    y.setSize(sf::Vector2f(SCREEN_WIDTH - _info->_xaxis, SCREEN_HEIGHT - _info->_yaxis));
    x.setOutlineThickness(4);
    y.setOutlineThickness(4);
    x.setFillColor(sf::Color::Transparent);
    y.setFillColor(sf::Color::Transparent);
    x.setPosition(0,0);
    y.setPosition(_info->_xaxis + 4, _info->_yaxis + 4);
    axis.push_back(x);
    axis.push_back(y);
    


    

}


void Graph::set_info(){

}
void Graph::update(graph_info* info){

}
void Graph::draw(sf::RenderWindow& window){
   window.clear();
    for (int i = 0; i < axis.size(); i++){
        window.draw(axis[i]);
    }
    for (int i = 0; i < system.size(); i++){
        window.draw(system[i]);
    }

}