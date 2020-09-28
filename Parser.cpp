//
//  Parser.cpp
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Parser.h"
//Takes in Token objects
//Checks the syntax
//Run this to see if you get "Success!" or "Failure!" appropriately for the tests on the website


Parser::Parser() {}

void Parser::Match(TokenType t) {
    
}

void Parser::Parse() {
    //try catch
}

void Parser::ParseDatalogProgram() {
    //SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    
}

void Parser::ParseSchemeList() {
    //scheme schemeList | lambda
    
}

void Parser::ParseFactList() {
    //fact factList | lambda
    
}

void Parser::ParseRuleList() {
    //rule ruleList | lambda
    
}

void Parser::ParseQueryList() {
    //query queryList | lambda
    
}

void Parser::ParseScheme() {
    //ID LEFT_PAREN ID idList RIGHT_PAREN
    
}

void Parser::ParseFact() {
    //ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    
}

void Parser::ParseRule() {
    //headPredicate COLON_DASH predicate predicateList PERIOD
    
}

void Parser::ParseQuery() {
    //predicate Q_MARK
    
}

void Parser::ParseHeadPredicate() {
    //ID LEFT_PAREN ID idList RIGHT_PAREN
    
}

void Parser::ParsePredicate() {
    //ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    
}

void Parser::ParsePredicateList() {
    //COMMA predicate predicateList | lambda
    
}

void Parser::ParseParameterList() {
    //COMMA parameter parameterList | lambda
    
}

void Parser::ParseStringList() {
    //COMMA STRING stringList | lambda
    
}

void Parser::ParseIdList() {
    //COMMA ID idList | lambda
    
}

void Parser::ParseParameter() {
    //STRING | ID | expression
    
}

void Parser::ParseExpression() {
    //LEFT_PAREN parameter operator parameter RIGHT_PAREN
    
}

void Parser::ParseOperater() {
    //ADD | MULTIPLY
    
}
