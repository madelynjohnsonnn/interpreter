//
//  UnterminatedStringAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/21/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "UnterminatedStringAutomaton.h"
#include <string>
#include <iostream>
using namespace std;

int UnterminatedStringAutomaton::Read(const string& input) {
    int inputRead = 0;
    string temp = input;
    value = "";
    newLines = 0;
    
    if (temp.length() > 0 && temp.substr(0,1) == "'") {
        value += temp[0];
        inputRead++;
        temp.erase(0,1);
        
        while (temp.length() > 0) {
//            if (temp.at(0) == EOF) {
//                return 0;
//            }
            if (temp.substr(0,1) == "'") {
                if (temp.length() > 0) {
                    if (temp.substr(1,1) != "'") { //string has ended
                        value += temp.substr(0,1);
                        inputRead++;
                        temp.erase(0,1);
                        return 0;
                    }
                    else { //at least 2 '
                        if (temp.length() >= 2 && temp.substr(0,2) == "''") { //apostrophe
                            value += temp.substr(0,2);
                            inputRead += 2;
                            temp.erase(0,2);
                        }
                        else { //good string
                            value += temp.substr(0,1);
                            inputRead++;
                            temp.erase(0,1);
                            return 0;
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
            else { //consuming characters in string
                value += temp.at(0);
                inputRead++;
                temp.erase(0,1);
            }
        }
    }
    return inputRead;
}

int UnterminatedStringAutomaton::NewLinesRead() const {
    return newLines;
}

Token* UnterminatedStringAutomaton::CreateToken(string input, int lineNumber) {
    return new Token(UNDEFINED, input, lineNumber);
}
