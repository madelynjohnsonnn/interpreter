//
//  UnterminatedCommentAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/21/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "UnterminatedCommentAutomaton.h"
#include <string>
#include <iostream>
using namespace std;

int UnterminatedCommentAutomaton::Read(const string& input) {
    int inputRead = 0;
    string temp = input;
    value = "";
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
            if (block == false && (temp.at(0) == '\n' /*|| temp.at(0) == EOF*/)) {
                //value += temp[0];
                inputRead++;
                temp.erase(0,1);
                newLines++;
                return 0;
            }
            else if (block == true && temp.length() > 0 && temp.at(0) == '|') {
                value += temp[0];
                inputRead++;
                temp.erase(0,1);
                
                if (temp.length() > 0 && temp.at(0) == '#') {
                    value += temp.substr(0,1);
                    inputRead ++;
                    temp.erase(0,1);
                    return 0;
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
    return inputRead;
}

int UnterminatedCommentAutomaton::NewLinesRead() const {
    return newLines;
}

Token* UnterminatedCommentAutomaton::CreateToken(string input, int lineNumber) {
    return new Token(UNDEFINED, input, lineNumber);
}
