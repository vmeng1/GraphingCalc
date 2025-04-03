#ifndef RPN_H
#define RPN_H

#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/function.h"
#include "../../includes/token/token.h"
#include "../../includes/token/constants.h"

class RPN{
    public:
        RPN(Queue <Token*> postfix);
        void set_input(Queue <Token*> postfix);
        float operator()();
        float operator()(float num);
        void print();
        friend ostream& operator <<(ostream& outs, RPN postfix);

    private: 
        Queue <Token*> _postfix;
};


#endif