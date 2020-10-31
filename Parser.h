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
    DatalogProgram* Parse1();
    void ParseDatalogProgram();
    void ParseSchemeList();
    void ParseFactList();
    void ParseRuleList();
    void ParseQueryList();
    void ParseScheme();
    Predicate* ParseFact();
    Rule* ParseRule();
    void ParseQuery();
    Predicate* ParseHeadPredicate();
    void ParseParameterList(Predicate* &p);
    void ParseStringList(Predicate* &p);
    void ParseIdList(Predicate* &p);
    Parameter* ParseParameter();
    void ParseEOF();
    void Domain(string);
    DatalogProgram* GetDatalog() { return datalog; }
    Predicate* ParseBodyPredicate();
    Parameter* ParseExpression();
    string ParseOperator();
    void ParseIdList(Rule* &r);
    Predicate* ParsePredicate();
    void ParsePredicateList(Rule* &r);
    
private:
    vector <Token*> tokens;
    unsigned int index;
    set <string> domain;
    //vector <Predicate*> predicates;
    DatalogProgram* datalog;
};

#endif /* Parser_h */
