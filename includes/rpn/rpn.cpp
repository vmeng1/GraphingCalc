#include "../../includes/rpn/rpn.h"

RPN::RPN(Queue <Token*> postfix){

    _postfix = postfix;

}

void RPN::set_input(Queue <Token*> postfix){

    _postfix = postfix;
}

float RPN::operator()(){
    Stack <Token*> stack;
    
    while (!_postfix.empty()){ 
        
        Token* token = _postfix.pop();
        if (token -> get_type() == 1){

            stack.push(token); //store num into stack
        }
        if (token ->get_type() == 5){
            stack.push(new Integer(3.14159));

        }
        if (token -> get_type() == 2 && token -> get_arg() == 2){
            if (stack.size() < 2){
                throw invalid_argument("Not enough arguments");
            }
            float num2 = stack.pop() -> get_num();
            float num1 = stack.pop() -> get_num();
            Token* result = new Integer(token->calculate(num1, num2));
            stack.push(result); 
        }
        else if(token -> get_type() == 2 && token -> get_arg() == 1){
            float num = stack.pop() -> get_num();
            Token* result = new Integer(token->calculate(num));
            stack.push(result); 
        }

    }


    return stack.pop() ->get_num();

}


float RPN::operator()(float num){
    Stack <Token*> stack;
    
    while (!_postfix.empty()){ 
        
        Token* token = _postfix.pop();
        if (token -> get_type() == 1){

            stack.push(token); //store num into stack
        }
        if (token ->get_type() == 4){
            stack.push(new Integer(num));

        }
        if (token ->get_type() == 5){
            stack.push(new Integer(3.14159));

        }
        if (token -> get_type() == 2 && token -> get_arg() == 2){
            if (stack.size() < 2){
                throw invalid_argument("Not enough arguments");
            }
           
            float num2 = stack.pop() -> get_num();
            float num1 = stack.pop() -> get_num();
            Token* result = new Integer(token->calculate(num1, num2));
            stack.push(result); 
        }
        else if(token -> get_type() == 2 && token -> get_arg() == 1){
            if (stack.size() < 1){
                throw invalid_argument("Not enough arguments");
            }
            float num = stack.pop() -> get_num();
            Token* result = new Integer(token->calculate(num));
            stack.push(result); 
        }
    }

    
    return stack.pop() ->get_num();

}


ostream& operator <<(ostream& outs, RPN postfix){
    outs << postfix();
    return outs;

}