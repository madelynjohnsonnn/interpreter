//
//  Parser.h
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include <vector>
#include "Token.h"
#include "Parser.h"
using namespace std;

class Parser {
public:
    Parser(vector <Token*> t);
    void Match(TokenType type);
    void Parse();
    void ParseDatalogProgram();
    void ParseSchemeList();
    void ParseFactList();
    void ParseRuleList();
    void ParseQueryList();
    void ParseScheme();
    void ParseFact();
    void ParseRule();
    void ParseQuery();
    void ParseHeadPredicate();
    void ParsePredicate();
    void ParsePredicateList();
    void ParseParameterList();
    void ParseStringList();
    void ParseIdList();
    void ParseParameter();
    void ParseExpression();
    void ParseOperator();
    void ParseEOF();
    void PrintDatalog();
private:
    vector <Token*> tokens;
    int index;
};

#endif /* Parser_h */
