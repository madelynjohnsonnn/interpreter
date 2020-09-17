//
//  Lexer.h
//  lab1
//
//  Created by Maddie Johnson on 9/14/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Lexer_h
#define Lexer_h

#include <stdio.h>
#include <string>
#include <vector>
#include "Token.h"
#include "Automaton.h"
#include "MatcherAutomaton.h"
#include "IdAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
using namespace std;

class Lexer {
public:
    Lexer();
    void run(string fileContents);
    void PrintTokens();
private:
    vector <Token*> tokens;
    vector <Automaton*> machines;
};

#endif /* Lexer_h */
