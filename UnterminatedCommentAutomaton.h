//
//  UnterminatedCommentAutomaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/21/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef UnterminatedCommentAutomaton_h
#define UnterminatedCommentAutomaton_h

#include <stdio.h>
#include <string>
#include "Automaton.h"
using namespace std;

class UnterminatedCommentAutomaton : public Automaton {
private:
    
public:
    UnterminatedCommentAutomaton(TokenType tokenType) : Automaton(tokenType) {
        this->type = UNDEFINED;
    };
    int Read(const string& input);
    int NewLinesRead() const;
    Token* CreateToken(string input, int lineNumber);
};

#endif /* UnterminatedCommentAutomaton_h */
