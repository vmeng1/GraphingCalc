#include "system.h"
#include "random.h"
#include "constants.h"
#include <iostream>

System::System(){
    cout << "hello" << endl;
    _g = new graph_info();
    _graph = Graph(_g);
}
System::System(graph_info* g)
{
   
    _g = g;
    _graph = Graph(_g);



}

void System::reset(graph_info* g){
    _g = g;
    _graph = Graph(_g);
}


void System::zoom_in(double mx, double my){
    
    _g->_xaxis += (_g->_xaxis - mx) * (1 - 0.5);
    _g->_yaxis += (_g->_yaxis - my) * (1 - 0.5);

    _g->_domain *= 0.5;
    

    _graph = Graph(_g); 
}

void System::zoom_out(double mx, double my){
    
    _g->_xaxis += (mx - _g->_xaxis) * (1 - 1 / 2.0);
    _g->_yaxis += (my - _g->_yaxis) * (1 - 1 / 2.0);


    _g->_domain *= 2.0;
    _graph = Graph(_g);  

}

void System::pan_left(){
   
    _g ->_xaxis = (_g ->_xaxis) - 100;
    _graph = Graph(_g);

}
void System::pan_right(){
   

    _g ->_xaxis = (_g ->_xaxis) + 100;

    _graph = Graph(_g);

}

void System::pan_up(){
     _g ->_yaxis = (_g ->_yaxis) + 100;
    _graph = Graph(_g);
}

void System::pan_down(){
     _g ->_yaxis = (_g ->_yaxis) - 100;
    _graph = Graph(_g);
}

void System::pan_by(int x, int y){
   
    _g->_xaxis += x;  // Increase x to pan left
    _g->_yaxis += y;  // Increase y to pan up

    
    _graph = Graph(_g); 
}

void System::Draw(sf::RenderWindow &window)
{
    _graph.draw(window);
}
