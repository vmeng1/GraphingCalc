#include "../token/token.h"

ostream& operator <<(ostream& outs, Token* token){

    token->print();
    return outs;
}