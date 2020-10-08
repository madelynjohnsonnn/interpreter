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
#include <set>
#include "Token.h"
#include "Parser.h"
#include "Predicate.h"
#include "Rule.h"
#include "PlainParameter.h"
#include "Expression.h"
#include "DatalogProgram.h"
using namespace std;

class Parser {
public:
    Parser(vector <Token*> t);
    void Match(TokenType type);
    void Parse();
    void ParseDatalogProgram();
    void ParseSchemeList();
    /*vector <Predicate>*/ void ParseFactList();
    /*vector <Rule>*/ void ParseRuleList();
    /*vector <Predicate>*/ void ParseQueryList();
    void ParseScheme();
    void ParseFact();
    void ParseRule();
    void ParseQuery();
    void ParseHeadPredicate();
    void ParsePredicate();
    void ParsePredicateList();
    void ParseParameterList(Predicate* &p);
    void ParseStringList(Predicate* &p);
    void ParseIdList(Predicate* &p);
    void ParseParameter(Predicate* &p);
    void ParseExpression(Predicate* &p);
    void ParseOperator(Predicate* &p);
    void ParseEOF();
    void Domain(string);
    DatalogProgram* GetDatalog() {
        return datalog;
    }
private:
    vector <Token*> tokens;
    int index;
    set <string> domain;
    vector <Predicate*> predicates;
    DatalogProgram* datalog;
};

#endif /* Parser_h */
