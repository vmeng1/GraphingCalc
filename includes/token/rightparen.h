#ifndef RPAREN_H
#define RPAREN_H

#include "../token/token.h"

class RightParen: public Token
{
    public:
        RightParen(){};
        int get_type(){return 10;}
        
    private:
        
};

#endif