#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "translate.h"
#include "graph.h"


#include <SFML/Graphics.hpp>

using namespace std;
class System
{
public:
    System();
    System(graph_info* g);
    void reset(graph_info* g);
    void zoom_in(double, double);
    void zoom_out(double, double);
    void pan_left();
    void pan_right();
    void pan_up();
    void pan_down();
    void pan_by(int deltaX, int deltaY);
    void Draw(sf::RenderWindow& window);
private:
    graph_info* _g;
    Graph _graph;
};

#endif // SYSTEM_H
