#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "constants.h"

using namespace std;

struct graph_info
{
    
    graph_info(){
        _eq = "x^2";
        _points = 5;
        _window_dim = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT/2);

        ifstream inputFile("inputHistory.txt"); // Open a file for reading
        if (inputFile.is_open()) {
        string history;
        
        while (getline(inputFile, history)) { // Read numbers from the file
        inputHistory.push_back(history);
        }
        inputFile.close(); // Close the file
        } else {
        cout << "Error opening file.\n";
    }

    }
        

    float _xaxis = WORK_PANEL/2;
    float _yaxis = SCREEN_HEIGHT/2;
    sf::Vector2f _window_dim;
    float _domain = 10.0;
    string _eq;
    int _points;
    vector<string> inputHistory;
    bool polar = false;


};

#endif