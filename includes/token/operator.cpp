
#include "../token/operator.h"

Operator::Operator(string symbol){
    _symbol = symbol;
    if (_symbol == "sin" || _symbol == "cos" || _symbol == "tan" || _symbol == "log" || _symbol == "sqrt"){
        _arg = 1;
    }
    else{
        _arg = 2;

    }


}

int Operator::get_op(){
    if (_symbol == "+" || _symbol == "-" ){
        return 1;
    }
    else if (_symbol == "*" || _symbol == "/"){
        return 2;
    }
    else if (_symbol == "^"){
        return 4;
    }
    else if (_symbol == "sin" || _symbol == "cos" || _symbol == "tan" ||_symbol == "log" ||_symbol == "sqrt"){
        return 3;
    }
    return 0;


}
float Operator::calculate(float num1, float num2){
    if (_symbol == "+"){
        return num1 + num2;
    }
    else if (_symbol == "-"){
        return num1 - num2;
    }
    else if (_symbol == "*"){
        return num1 * num2;
    } 
    else if (_symbol == "/"){
        return num1/num2;
    }
    else if(_symbol == "^"){
        return pow(num1,num2);

    }
    return 0;
}


float Operator::calculate(float num){
    if(_symbol == "sin"){
        return sin(num);
    }
    else if(_symbol == "cos"){
        return cos(num);
    }
    else if(_symbol == "tan"){
        return tan(num);
    }
    else if(_symbol == "log"){
        return log(num);
    }
    else if(_symbol == "sqrt"){
        return sqrt(num);
    }
    return 0;
}

void Operator::print(){
    cout << _symbol;

}