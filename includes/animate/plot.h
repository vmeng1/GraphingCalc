#ifndef PLOT_H
#define PLOT_H

#include "graph_info.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "translate.h"
#include <string.h>
#include <string>
#include <cctype>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <cmath>

class Plot
{
    public:
        Plot();
        Plot(graph_info* info);
        void set_info();
        vector<sf::Vector2f> operator()(); //returns a vector of (screen) coords
    private:
        graph_info* _info;
        Queue <Token*> _postfix;
        
};
#endif