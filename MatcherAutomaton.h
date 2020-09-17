//
//  MatcherAutomaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef MatcherAutomaton_h
#define MatcherAutomaton_h

#include <stdio.h>
#include <string>
#include "Automaton.h"
using namespace std;

class MatcherAutomaton : public Automaton {
private:
    string toMatch;
public:
    MatcherAutomaton(string toMatch, TokenType tokenType) : Automaton(tokenType) { this->type = tokenType; this->toMatch = toMatch;};
    int Read(const string& input);
    int NewLinesRead() const;
    Token* CreateToken(string input, int lineNumber);
    string GetMatch();
};


#endif /* MatcherAutomaton_h */
