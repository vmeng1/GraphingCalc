#ifndef INTEGER_H
#define INTEGER_H

#include "../token/token.h"

class Integer:public Token
{
    public:
        Integer(float integer);
        Integer (string variable);
        float get_num(){return _integer;}
        int get_type(){return 1;}
        void print();
    private:
        float _integer;
};

#endif