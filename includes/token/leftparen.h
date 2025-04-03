#ifndef LPAREN_H
#define LPAREN_H

#include "../token/token.h"

class LeftParen: public Token
{
    public:
        LeftParen(){};
        int get_type(){return 0;}
        int get_op() {return 0;}
        void print(){
            cout << "( ";
        }
        
    private:
        
};

#endif