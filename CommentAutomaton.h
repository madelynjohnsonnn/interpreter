//
//  CommentAutomaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef CommentAutomaton_h
#define CommentAutomaton_h

#include <stdio.h>
#include <string>
#include "Automaton.h"
using namespace std;

class CommentAutomaton : public Automaton {
private:
    
public:
    CommentAutomaton(TokenType tokenType) : Automaton(tokenType) {
        this->type = COMMENT;
    };
    int Read(const string& input);
    int NewLinesRead() const;
    Token* CreateToken(string input, int lineNumber);
};


#endif /* CommentAutomaton_h */
