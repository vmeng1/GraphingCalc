#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"

animate::animate() : sidebar(WORK_PANEL, SIDE_BAR)

{
    
    isInputBoxVisible = false; 
    inputBox.setSize(sf::Vector2f(300, 100)); // Width and height
    inputBox.setFillColor(sf::Color::White); 
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);
    inputBox.setPosition(sf::Vector2f(50, 50)); // Adjust position

    inputText.setFont(font); // Use the already loaded font
    inputText.setString(userInput);
    inputText.setCharacterSize(20);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(inputBox.getPosition().x + 10, inputBox.getPosition().y + 5); // Padding
    userInput = ""; 
    cout << "animate CTOR: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");

    // VideoMode class has functions to detect screen size etc.
    // RenderWindow constructor has a third argumnet to set style
    // of the window: resize, fullscreen etc.

    // System will be implemented to manage a vector of objects to be animated.
    //   at that point, the constructor of the System class will take a vector
    //   of objects created by the animate object.
    //   animate will
    _g = new graph_info();
    system = System(_g);
    window.setFramerateLimit(60);

    mouseIn = true;

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout << "Geme CTOR. preparing to load the font." << endl;
    //--- FONT ----------
    // font file must be in the "working directory:
    //      debug folder
    // Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    // font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    
    
    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - myTextLabel.getLocalBounds().height - 5));
    cout << "animate instantiated successfully." << endl;

}

void animate::Draw()
{
    // Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn)
    {
        window.draw(mousePoint);
    }
    if (isInputBoxVisible){
        window.draw(inputBox);
        inputText.setString(userInput);
        window.draw(inputText); 

    }
    if (showError) {
    sf::Text errorText;
    errorText.setFont(font); // Use your existing font
    errorText.setString(errorMessage);
    errorText.setCharacterSize(18);  // Adjust size
    errorText.setFillColor(sf::Color::Red); // Use a distinct color for errors
    errorText.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - myTextLabel.getLocalBounds().height - 5)); // Position below the input box
    window.draw(errorText);
}

   sidebar.draw(window);

  
    

    //- - - - - - - - - - - - - - - - - - -
    // getPosition() gives you screen coords, getPosition(window) gives you window coords
    // cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    // drawing Test: . . . . . . . . . . . .
    // This is how you draw text:)
    //window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update()
{
    // cause changes to the data for the next frame
    
    if (mouseIn)
    {
        // mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x - 5,
                               sf::Mouse::getPosition(window).y - 5);

        // mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    }
}
void animate::render()
{
    window.clear();
    Draw();
    window.display();
    
}

void animate::processEvents()
{
    sf::Event event;
    ofstream output_file("inputHistory.txt");
    float mouseX, mouseY;
    static bool isMousePressed = false;
    static sf::Vector2i mousePressPosition;
    while (window.pollEvent(event)) // or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
        for(int i = 0; i< _g->inputHistory.size(); i++){
                output_file << _g->inputHistory[i] << endl;
        }
            window.close();
            break;

        // key pressed
        
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::F)
            {
                isInputBoxVisible = !isInputBoxVisible; // Toggle input box visibility
                userInput = "";
                cout << "F" << endl;


            }
            else{
        
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                system.pan_right();
               
                
                break;
            case sf::Keyboard::Right:
                sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                system.pan_left();
                
                break;
            case sf::Keyboard::Up:
                sidebar[SB_KEY_PRESSED] = "UP ARROW";
                system.pan_up();
                
                break;
            case sf::Keyboard::Down:
                sidebar[SB_KEY_PRESSED] = "DOWN ARROW";
                system.pan_down();
                
                break;
            case sf::Keyboard::G:
                sidebar[SB_KEY_PRESSED] = "G";
                system.zoom_in(sf::Mouse::getPosition(window).x - 5,
                               sf::Mouse::getPosition(window).y - 5);
                break;
            case sf::Keyboard::H:
                sidebar[SB_KEY_PRESSED] = "H";
                system.zoom_out(sf::Mouse::getPosition(window).x - 5,
                               sf::Mouse::getPosition(window).y - 5);
                break;

            case sf::Keyboard::Escape:
                sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                for(int i = 0; i< _g->inputHistory.size(); i++){
                    output_file << _g->inputHistory[i] << endl;
                }
                window.close();
            case sf::Keyboard::P:
                sidebar[SB_KEY_PRESSED] = "P";
                if(!isInputBoxVisible){
                 _g->polar = !_g->polar;   
                }
                system.reset(_g);

                break;
            default:
                break;
            
            }

            break;
        }
            
        case sf::Event::TextEntered:
            if (isInputBoxVisible && (event.text.unicode < 128 &&  (event.text.unicode > 31 || event.text.unicode == 8))) {
                char enteredChar = static_cast<char>(event.text.unicode);

                if (enteredChar == '\b') { // Handle backspace
                    if (!userInput.empty())
                        userInput.pop_back();
                        showError = false;
                } 
                else if (enteredChar == 'z') { // Handle Enter
                    try {
                        // Validate the input expression
                    validateInput(userInput);

                    cout << "Input saved: " << userInput << endl;
                    _g-> _eq = userInput;
                    cout << "_g-> _eq " << _g->_eq << endl;
                    try {
                        system.reset(_g); 
                    }
                    catch (const invalid_argument& e) {
                        // Handle invalid postfix exception
                        cerr << "Error: " << e.what() << endl;
                        errorMessage = e.what();  // Store error message for display (if needed)
                        showError = true;      
                        return;
                    }
                    _g -> inputHistory.push_back(userInput); // Add to history
                    isInputBoxVisible = !isInputBoxVisible;
                    sidebar.setInputHistory(_g -> inputHistory);
                    showError = false;
                    }
                catch (const invalid_argument& e) {
                // Catch invalid input exception and show the error message
                    cout << "Error: " << e.what() << endl;
                    errorMessage = e.what();  // Save the error message
                    showError = true;         // Set error state
            
                    }
                } 
                else if (enteredChar != 'F' && enteredChar != 'f'){
                    userInput += enteredChar; // Add character to input
                }

                inputText.setString(userInput); // Update displayed text
    
            }
            break;
        
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            // Do something with it if you need to...
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                isMousePressed = true;  // Mouse press initiated
                mousePressPosition = sf::Mouse::getPosition(window);  // Store the position of the click
            }
            break;
        
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if(sf::Mouse::getPosition(window).y > 125 + _g -> inputHistory.size() && sf::Mouse::getPosition(window).y < 125 + 25 * _g -> inputHistory.size() && sf::Mouse::getPosition(window).x > WORK_PANEL +20 ){
                    _g ->_eq = _g ->inputHistory[(sf::Mouse::getPosition(window).y - 125)/25];
                    system.reset(_g);
                }

                if (isMousePressed)
                {
                    // Get the release position
                    sf::Vector2i mouseReleasePosition = sf::Mouse::getPosition(window);

                    // Calculate the movement delta
                    int x = mouseReleasePosition.x - mousePressPosition.x;
                    int y = mouseReleasePosition.y - mousePressPosition.y;

                    // Pan the view by the difference in position
                    if (abs(x) > 0 || abs(y) > 0)
                    {
                        system.pan_by(x, y);  // Adjust pan logic
                    }

                    isMousePressed = false;  // Reset mouse pressed state
                }
            }
            break;

        default:
            break;
        }
    }
}
void animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); // clear/draw/display
    }
    cout << endl
         << "-------ANIMATE MAIN LOOP EXITING ------------" << endl;
}

string mouse_pos_string(sf::RenderWindow &window)
{
    return "(" +
           to_string(sf::Mouse::getPosition(window).x) +
           ", " +
           to_string(sf::Mouse::getPosition(window).y) +
           ")";
}




void animate::validateInput(const string& input) {
    // Check if the input is empty
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }

    // Check for invalid characters
    for (char ch : input) {
        if (!isalnum(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/' && 
            ch != '^' && ch != '(' && ch != ')' && ch != '.' && ch != ' ') {
            throw invalid_argument("Input contains invalid characters.");
        }
    }

    // parenthesis matching
    int count = 0;
    for (char ch : input) {
        if (ch == '(') {
            count++;
        }
        if (ch == ')'){
            count--;  
        } 
        if (count < 0) {
            throw invalid_argument("Mismatched parentheses.");
        }
    }
    if (count != 0) {
        throw invalid_argument("Mismatched parentheses.");
    }



    // (Optional) Validate function calls like "sin", "cos", etc.
    static const vector<string> validFunctions = {"sin", "cos", "tan", "log", "sqrt"};
    for (const auto& func : validFunctions) {
        size_t pos = input.find(func);
        while (pos != string::npos) {
            if (pos + func.size() < input.size() && isalnum(input[pos + func.size()])) {
                throw invalid_argument("Invalid usage of function: " + func);
            }
            pos = input.find(func, pos + func.size());
        }
    }

    size_t divPos = input.find('/');
    while (divPos != string::npos) {
        // Look ahead to the next character after the '/'
        size_t nextPos = divPos + 1;
        if (nextPos < input.size() && input[nextPos] == '0') {
            // Check if the next character is '0'
            throw invalid_argument("Division by zero is not allowed.");
        }
        divPos = input.find('/', divPos + 1);
    }

    // Additional syntax checks (optional, depending on your application)
    // For example: ensuring operators are used correctly
}
