//
//  IdAutomaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef IdAutomaton_h
#define IdAutomaton_h

#include <stdio.h>
#include <string>
#include "Automaton.h"
using namespace std;

class IdAutomaton : public Automaton {
private:
    
public:
    IdAutomaton(TokenType tokenType) : Automaton(tokenType) {
        this->type = ID;
    };
    int Read(const string& input);
    int NewLinesRead() const;
    Token* CreateToken(string input, int lineNumber);
};

#endif /* IdAutomaton_h */
