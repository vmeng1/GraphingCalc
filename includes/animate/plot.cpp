#include "plot.h"


Plot::Plot(){
    _info = nullptr;
    _postfix = Queue<Token*>();

}
Plot::Plot(graph_info* info){
    _info = info;
    _postfix = Queue<Token*>();
    
}
void Plot::set_info(){
    Queue<Token *> infix;
    string eq = _info -> _eq; 
    if (eq[0] == '-'){
        infix.push(new Integer(0));
    }
    for (int i = 0; i < eq.length(); i++){
            
        // --------- math operators ------------//
            if(eq[i] == '+'){
                infix.push(new Operator("+"));
            }
            if(eq[i] == '-'){
                infix.push(new Operator("-"));
            }
            if(eq[i] == '*'){
                infix.push(new Operator("*"));
            }
            if(eq[i] == '/'){
                infix.push(new Operator("/"));
            }
            if(eq[i] == '^'){
                infix.push(new Operator("^"));
            }

        // --------- numbers ------------//
        if (isdigit(eq[i])) {  // If number (includes integers and decimals)
            string num;
            while (isdigit(eq[i])) {  // Process the integer part
                num += eq[i];
                i++;
            }
    
        // Check if a decimal point exists
        if (eq[i] == '.') {
            num += eq[i];  // Add the decimal point
            i++;  // Move past the decimal point
        
            // Continue reading the fractional part
        while (isdigit(eq[i])) {
            num += eq[i];
            i++;
            }
        }

            i--;  // Adjust i back to the last processed character
        infix.push(new Integer(num));  // Add the number to infix

        if (isalpha(eq[i+1])) {  // Check if next is a character (e.g., variable)
            infix.push(new Operator("*"));
        }
        }

        if(eq[i] == 'X' || eq[i] == 'x'){
            infix.push(new Function("X"));

            if(isalpha(eq[i+1])){ //check if next is char
                infix.push(new Operator("*"));
            }
        }
        // --------- pi ------------//
        if (eq[i] == 'p' && eq.substr(i, 2) == "pi") {
            infix.push(new Integer(3.14159)); 
            i++; // Skip the rest of the word
            if(isalpha(eq[i+1])){ //check if next is char
                infix.push(new Operator("*"));
            }
            if(isdigit(eq[i+1])){ //check if next is char
                infix.push(new Operator("*"));
            }
        }
        
        
        // --------- trig operators ------------//
            if (eq[i] == 's' && eq.substr(i, 3) == "sin"){
                infix.push(new Operator("sin"));
                i+=2;
                if (i + 1 >= eq.length() || eq[i + 1] != '(') {
                    throw invalid_argument("Missing argument for 'sin'");
                }

            }

            if (eq[i] == 't' && eq.substr(i, 3) == "tan"){
                infix.push(new Operator("tan"));
                i+=2;
                if (eq[i+1] != '('){
                     throw invalid_argument("Missing argument");
                }
            }
            if (eq[i] == 'c' && eq.substr(i, 3) == "cos"){
                infix.push(new Operator("cos"));
                i+=2;
                if (eq[i+1] != '('){
                     throw invalid_argument("Missing argument");
                }
            }
        // --------- parenthesis ------------//
        if(eq[i] == '('){
                infix.push(new LeftParen());
                if (i+1 < eq.length() && eq[i+1] == '-'){
                infix.push(new Integer(0));
            }
        }
        if(eq[i] == ')'){
                infix.push(new RightParen());
                if (i+1 < eq.length() && isalpha(eq[i+1])){
                    infix.push(new Operator ("*"));
                }
                if (i+1 < eq.length() && isdigit(eq[i+1])){
                    infix.push(new Operator ("*"));
                }
        }
        // --------- log ------------//
        if (eq[i] == 'l' && eq.substr(i, 3) == "log") {
            infix.push(new Operator("log")); // Push log function as an operator
            i += 2; // Skip the rest of the word
        }
        // --------- sqrt ------------//
        if (eq[i] == 's' && eq.substr(i, 4) == "sqrt") {
            infix.push(new Operator("sqrt")); // Push log function as an operator
            i += 3; // Skip the rest of the word
        }
    }
    ShuntingYard sy(infix);
    _postfix = sy.postfix();
    cout << "_postfix: " << _postfix << endl;
    if (_postfix.empty()) {
        throw invalid_argument("Invalid expression: Postfix is empty.");
    }


}
vector<sf::Vector2f> Plot::operator()(){
    sf::Vector2f coords;
    vector<sf::Vector2f> points;
    Coord_Translate point(_info);
    sf::Vector2f left = point.untranslate(0,0);

   

    if(!_info->polar)
    {
        for (float i = left.x; i <= left.x + _info -> _domain ;i+= _info->_domain/300){
            RPN rpn(_postfix);
            coords = point.translate(i, rpn(i));
            //cout << "coord: " << coords.x << endl;
            points.push_back(coords);
        }
        return points;
    }
    else
    {
        for (float i = 0; i <= 100 ;i+= 0.01){
            RPN rpn(_postfix);
            double r = rpn(i);
            double x = r * cos(i);
            double y = r * sin(i);
            coords = point.translate(x,y);

            //cout << "coord: " << coords.x << endl;
            points.push_back(coords);
        }
        return points;
    }


} //returns a vector of (screen) coords