//
//  CommentAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "CommentAutomaton.h"
#include <string>
using namespace std;

int CommentAutomaton::Read(const string& input) {
    int inputRead = 0;
    string temp = input;
    string state = "";
    value = "";
    
    while (temp.length() > 0) {
        
        if (temp.at(0) == '#') {
            value += temp[0];
            inputRead++;
            temp.erase(0,1);
            
            if (temp.length() > 0 && temp.at(0) == '|') {
                value += temp[0];
                inputRead++;
                temp.erase(0,1);
                state = "blockComment";
            }
        }
        
        
    }
    
    
        
        if (temp.at(0) == '|') {
            value += temp[0];
            inputRead++;
            temp.erase(0,1);
            
            if (temp.at(0) == '|' && temp.at(1) == '#') {
                
            }
        }
        
        
        for (int i = 0; i < temp.size(); i++) {
            while (temp.substr(i,i) != "/n") {
                
            }
        }
    
    
//    if (isalpha(temp.at(0))) {
//        value += temp[0];
//        inputRead++;
//        temp.erase(0,1);
//
//        while (isalnum(temp.at(0))) {
//            value += temp.at(0);
//            inputRead++;
//            temp.erase(0,1);
//        }
//
//    }
    
    return inputRead;
}

int CommentAutomaton::NewLinesRead() const {
    return newLines;
}

Token* CommentAutomaton::CreateToken(string input, int lineNumber) {
    return new Token(COMMENT, input, lineNumber);
}



/*
string CommentAutomaton::Parse() {
    //LINE COMMENT
    if (input.substr(0) == "#") {
        for (int i = 0; i < input.size(); i++) {
            while (input.substr(i,i) != "/n") {
                
            }
        }
    }
    
    //BLOCK COMMENT
    
    
    return NULL;
}
*/
