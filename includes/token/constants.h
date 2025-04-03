#ifndef CONSTANT_H
#define CONSTANT_H

#include "../token/token.h"

class pi : public Token {
public:
    pi(string pi) {_pi = 3.14159;}
    int get_type() { return 5; }
    float get_num(){return _pi;}

private:
    float _pi;
};

#endif
