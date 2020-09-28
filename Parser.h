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
#include "Token.h"
using namespace std;

class Parser {
public:
    Parser();
    void Match(TokenType t);
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
    void ParseOperater();
private:
    
};

#endif /* Parser_h */
