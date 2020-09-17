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
    
    //checking keywords
    if (temp.substr(0,7) == "Schemes" || temp.substr(0,5) == "Facts" || temp.substr(0,5) == "Rules" || temp.substr(0,7) == "Queries") {
        return 0;
    }
    
    if (isalpha(temp.at(0))) {
        value += temp[0];
        inputRead++;
        temp.erase(0,1);
        
        while (isalnum(temp.at(0))) {
            value += temp.at(0);
            inputRead++;
            temp.erase(0,1);
        }
        
    }
    
    return inputRead;
}

int IdAutomaton::NewLinesRead() const {
    return 0;
}

Token* IdAutomaton::CreateToken(string input, int lineNumber) {
    return new Token(ID, input, lineNumber);
}
