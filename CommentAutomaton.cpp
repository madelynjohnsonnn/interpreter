//
//  CommentAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "CommentAutomaton.h"
#include <string>
#include <iostream>
using namespace std;

int CommentAutomaton::Read(const string& input) {
    int inputRead = 0;
    string temp = input;
    value = "";
    newLines = 0;
    bool block = false;
    
    if (temp.length() > 0 && temp.at(0) == '#') {
        value += temp[0];
        inputRead++;
        temp.erase(0,1);
        
        if (temp.length() > 0 && temp.at(0) == '|') {
            value += temp[0];
            inputRead++;
            temp.erase(0,1);
            block = true;
        }
        
        while (temp.length() > 0) {
            if (block == false && (temp.at(0) == '\n')) {
                //value += temp[0];
                inputRead++;
                temp.erase(0,1);
                newLines++;
                return inputRead;
            }
            else if (block == true && temp.length() > 0 && temp.at(0) == '|') {
                value += temp[0];
                inputRead++;
                temp.erase(0,1);
                
                if (temp.length() > 0 && temp.at(0) == '#') {
                    value += temp.substr(0,1);
                    inputRead ++;
                    temp.erase(0,1);
                    return inputRead;
                }
                else {
                    //nothing
                }
            }
            else if (temp.at(0) == '\n') {
                newLines++;
                value += temp.at(0);
                inputRead++;
                temp.erase(0,1);
            }
//            else if (temp.at(0) == EOF) {
//                return 0;
//            }
            else {
                value += temp[0];
                inputRead++;
                temp.erase(0,1);
            }
        }
    }
    return 0;
}

int CommentAutomaton::NewLinesRead() const {
    return newLines;
}

Token* CommentAutomaton::CreateToken(string input, int lineNumber) {
    return new Token(COMMENT, input, lineNumber);
}
