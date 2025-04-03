#include "../token/integer.h"


Integer::Integer(float integer){
    _integer = integer;

}

Integer::Integer(string variable){
    _integer = stoi(variable);
}

void Integer::print(){

    cout << _integer << " ";
}