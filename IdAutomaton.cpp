//
//  IdAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "IdAutomaton.h"
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

int IdAutomaton::Read(const string& input) {
    //letter followed by 0 or more letters or digits, not keyword
    
    int inputRead = 0;
    string temp = input;
    value = "";
    
    if (temp.length() > 0 && isalpha(temp.at(0))) {
        value += temp[0];
        inputRead++;
        temp.erase(0,1);
        
        while (temp.length() > 0 && isalnum(temp.at(0))) {
            value += temp.at(0);
            inputRead++;
            temp.erase(0,1);
        }
        
    }
    
    if (value == "Schemes" || value == "Queries" || value == "Facts" || value == "Rules") {
        return 0;
    }
    
    
//    if (temp.length() >= 7 && (temp.substr(0,7) == "Schemes" || temp.substr(0,7) == "Queries")) {
//        return 0;
//    }
//
//    if (temp.length() >= 5 && (temp.substr(0,5) == "Facts" || temp.substr(0,5) == "Rules")) {
//        return 0;
//    }
    
    return inputRead;
}

int IdAutomaton::NewLinesRead() const {
    return 0;
}

Token* IdAutomaton::CreateToken(string input, int lineNumber) {
    return new Token(ID, input, lineNumber);
}
