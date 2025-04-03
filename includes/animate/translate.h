#ifndef TRANSLATE_H
#define TRANSLATE_H
#include "constants.h"
#include "graph_info.h"


class Coord_Translate
{
    public:
        Coord_Translate();
        Coord_Translate(graph_info* info);
        sf::Vector2f translate(float x, float y);
        sf::Vector2f untranslate(float _x, float _y);
        sf::Vector2f operator()(float x, float y);
    
    private:
        graph_info* _info;
};


#endif