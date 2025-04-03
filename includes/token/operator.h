#ifndef OPERATOR_H
#define OPERATOR_H

#include "../token/token.h"
#include <math.h>
#include <cmath>

class Operator: public Token
{
    public:
        Operator(string symbol);
        int get_type(){return 2;}
        int get_op();
        float calculate(float num1, float num2);
        float calculate(float num);
        int get_arg(){return _arg;}
        void print();
    private:
        string _symbol;
        int _arg;
};

#endif