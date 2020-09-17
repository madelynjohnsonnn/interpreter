//
//  StringAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "StringAutomaton.h"
#include <string>
#include <iostream>
using namespace std;

int StringAutomaton::Read(const string& input) {
    int inputRead = 0;
    string temp = input;
    value = "";
    
    if (temp.substr(0,1) == "'") {
        value += temp[0];
        inputRead++;
        temp.erase(0,1);
        
        while (temp.length() > 0) {
            if (temp.at(0) == EOF) {
                return 0;
            }
            else if (temp.substr(0,1) == "'") {
                if (temp.length() > 0) {
                    if (temp.substr(1,1) != "'") {
                        value += temp.substr(0,1);
                        inputRead++;
                        temp.erase(0,1);
                        return inputRead;
                    }
                    else {
                        if (temp.substr(0,2) == "''") {
                            value += temp.substr(0,2);
                            inputRead += 2;
                            temp.erase(0,2);
                        }
                        else {
                            value += temp.substr(0,1);
                            inputRead++;
                            temp.erase(0,1);
                        }
                    }
                }
            }
            else if (temp.at(0) == '\n') {
                newLines++;
                value += temp.at(0);
                inputRead++;
                temp.erase(0,1);
            }
            else {
                value += temp.at(0);
                inputRead++;
                temp.erase(0,1);
            }
        }
    }
    return inputRead;
}

int StringAutomaton::NewLinesRead() const {
    return newLines;
}

Token* StringAutomaton::CreateToken(string input, int lineNumber) {
    return new Token(STRING, input, lineNumber);
}
