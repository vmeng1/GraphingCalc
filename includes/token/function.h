#ifndef FUNCTION_H
#define FUNCTION_H

#include "../token/token.h"

class Function:public Token
{
    public:
        Function(string variable);
        int get_type(){return 4;}
        void print();
    private:
        string _variable;
        


};

#endif