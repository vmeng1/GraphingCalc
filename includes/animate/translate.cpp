#include "translate.h"

Coord_Translate::Coord_Translate(){
    _info = nullptr;
}
Coord_Translate::Coord_Translate(graph_info* info){
    _info = info;
}
sf::Vector2f Coord_Translate::translate(float x, float y){
    float _x = (_info->_xaxis) + (x/(_info->_domain)) * WORK_PANEL;
    float _y = (_info ->_yaxis) - (y/(_info->_domain)) * SCREEN_HEIGHT;
   
    return sf::Vector2f (_x,_y);

}
sf::Vector2f Coord_Translate::untranslate(float _x, float _y){
    float x = (_info->_domain/WORK_PANEL)*(_x - _info->_xaxis);
    cout << "x: " << x;
    float y = (_info->_domain/SCREEN_HEIGHT)*(_y + _info->_yaxis);
    return sf::Vector2f (x,y);
}
sf::Vector2f Coord_Translate::operator()(float x, float y){
    return translate(x,y);
}
