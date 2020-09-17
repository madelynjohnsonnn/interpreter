//
//  StringAutomaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef StringAutomaton_h
#define StringAutomaton_h

#include <stdio.h>
#include <string>
#include "Token.h"
#include "Automaton.h"
using namespace std;

class StringAutomaton : public Automaton {
private:
    
public:
    StringAutomaton(TokenType tokenType) : Automaton(tokenType) {
        this->type = STRING;
    };
    int Read(const string& input);
    int NewLinesRead() const;
    Token* CreateToken(string input, int lineNumber);
};

#endif /* StringAutomaton_h */
