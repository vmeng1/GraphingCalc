
 #include "../token/function.h"
 
 Function::Function(string variable){
    _variable = variable;
 }

 void Function::print(){

    cout << _variable;
}