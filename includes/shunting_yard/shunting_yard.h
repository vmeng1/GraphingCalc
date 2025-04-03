
#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/token.h"
#include "../../includes/token/function.h"



class ShuntingYard{
    public: 
        ShuntingYard(){}
        ShuntingYard(Queue <Token*> infix);
        void infix(Queue <Token*> input);
        Queue <Token*> postfix();
        Queue <Token*> postfix(Queue <Token*> input);
        
    private: 
        Queue <Token*> _infix;
};

#endif