#ifndef TOKEN_H_
#define TOKEN_H_

//like a creature



#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;

class Token{
    public:
        Token(){}
        virtual float get_num(){return 0;}
        virtual int get_type(){return 0;}
        virtual int get_op(){return 0;}
        virtual int get_arg(){return 0;}
        virtual float calculate(float num1, float num2){return 0;}
        virtual float calculate(float num){return 0;}
        virtual void print(){}

        friend ostream& operator <<(ostream& outs, Token* token);

};




#endif 
