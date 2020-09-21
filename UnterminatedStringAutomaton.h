//
//  UnterminatedStringAutomaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/21/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef UnterminatedStringAutomaton_h
#define UnterminatedStringAutomaton_h

#include <stdio.h>
#include <string>
#include "Token.h"
#include "Automaton.h"
using namespace std;

class UnterminatedStringAutomaton : public Automaton {
private:
    
public:
    UnterminatedStringAutomaton(TokenType tokenType) : Automaton(tokenType) {
        this->type = UNDEFINED;
    };
    int Read(const string& input);
    int NewLinesRead() const;
    Token* CreateToken(string input, int lineNumber);
};

#endif /* UnterminatedStringAutomaton_h */
