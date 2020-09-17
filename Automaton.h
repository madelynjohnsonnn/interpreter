//
//  Automaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Automaton_h
#define Automaton_h
#include <stdio.h>
#include "Token.h"
#include <string>

class Automaton {
protected:
    int newLines = 0;
    TokenType type;
    string value;
public:
    Automaton(TokenType type) { this->type = type; }
    virtual int Read(const std::string& input) = 0;
    virtual Token* CreateToken(std::string input, int lineNumber) {
        return new Token(type, input, lineNumber);
    }
    virtual int NewLinesRead() const { return newLines; }
//    virtual string GetMatch() { return NULL; }
    TokenType GetType() { return type; }
    string GetValue() { return value; }
};


#endif /* Automaton_h */
