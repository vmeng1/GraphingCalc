#include "../../includes/shunting_yard/shunting_yard.h"

ShuntingYard::ShuntingYard(Queue <Token*> infix){

    _infix = infix;

}

void ShuntingYard::infix(Queue <Token*> input){
    _infix = input;

}


Queue <Token*> ShuntingYard::postfix(){ //returns a queue
    Stack <Token*> stack;
    Queue <Token*> postfix;
    while (!_infix.empty()){
       
        Token* token = _infix.pop();
        if (token -> get_type() == 1 || token ->get_type() ==4){ //if num or x
            postfix.push(token);
              
        }
        if (token->get_type() == 5) { // if π
            postfix.push(token);
        }
        if (token-> get_type() == 2){
            
            
            while((!stack.empty()) && (token -> get_op()) <= (stack.top() ->get_op())){ 
                postfix.push(stack.pop());
            }
          
            stack.push(token);
 
           
        } 
        if (token ->get_type() == 0){
            stack.push(token);
               
              
        }
        if (token->get_type() ==10){ //right paren
            while (stack.top()->get_type() != 0){
                postfix.push(stack.pop());

            }
            stack.pop(); 
          
        }
       
    }
    
    while (!stack.empty()){
            postfix.push(stack.pop());
        }
   
    return postfix;

}


 Queue <Token*> ShuntingYard::postfix(Queue <Token*> input){

    _infix = input;
    return postfix();
 }
