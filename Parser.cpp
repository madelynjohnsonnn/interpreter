//
//  Parser.cpp
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Parser.h"
#include <vector>
#include <iostream>
using namespace std;

Parser::Parser(vector <Token*> t) {
    index = 0;
    tokens = t;
}

//TODO Datalog Parse();

void Parser::Parse() {
    try {
        ParseDatalogProgram();
    }
    catch (Token* error) {
        cout << "Failure!" << endl;
        cout << "\t" << error->toString() << endl;
    }
}

void Parser::Match(TokenType type) {
    if (tokens.size() >= index) {
        Token* token = tokens.at(index);
        if (token->GetType() == type) {
            index++;
            return;
        }
        throw token;
    }
    else {
        cout << "no more tokens" << endl;
    }
}

void Parser::ParseDatalogProgram() {
    //SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    Match(SCHEMES);
    Match(COLON);
    ParseScheme();
    ParseSchemeList();
    Match(FACTS);
    Match(COLON);
    ParseFactList();
    Match(RULES);
    Match(COLON);
    ParseRuleList();
    Match(QUERIES);
    Match(COLON);
    ParseQuery();
    ParseQueryList();
    ParseEOF();
}

void Parser::ParseSchemeList() {
    //scheme schemeList | lambda
    if (tokens.at(index)->GetType() == ID) {
        ParseScheme();
        ParseSchemeList();
    }
}

void Parser::ParseFactList() {
    //fact factList | lambda
    if (tokens.at(index)->GetType() == ID) {
        ParseFact();
        ParseFactList();
    }
}

void Parser::ParseRuleList() {
    //rule ruleList | lambda
    if (tokens.at(index)->GetType() == ID) {
        ParseRule();
        ParseRuleList();
    }
}

void Parser::ParseQueryList() {
    //query queryList | lambda
    if (tokens.at(index)->GetType() == ID) {
        ParseQuery();
        ParseQueryList();
    }
}

void Parser::ParseScheme() {
    //ID LEFT_PAREN ID idList RIGHT_PAREN
    Match(ID);
    Match(LEFT_PAREN);
    Match(ID);
    ParseIdList();
    Match(RIGHT_PAREN);
}

void Parser::ParseFact() {
    //ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    Match(ID);
    Match(LEFT_PAREN);
    Match(STRING);
    ParseStringList();
    Match(RIGHT_PAREN);
    Match(PERIOD);
}

void Parser::ParseRule() {
    //headPredicate COLON_DASH predicate predicateList PERIOD
    ParseHeadPredicate();
    Match(COLON_DASH);
    ParsePredicate();
    ParsePredicateList();
    Match(PERIOD);
}

void Parser::ParseQuery() {
    //predicate Q_MARK
    ParsePredicate();
    Match(Q_MARK);
}

void Parser::ParseHeadPredicate() {
    //ID LEFT_PAREN ID idList RIGHT_PAREN
    Match(ID);
    Match(LEFT_PAREN);
    Match(ID);
    ParseIdList();
    Match(RIGHT_PAREN);
}

void Parser::ParsePredicate() {
    //ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    Match(ID);
    Match(LEFT_PAREN);
    ParseParameter();
    ParseParameterList();
    Match(RIGHT_PAREN);
}

void Parser::ParsePredicateList() {
    //COMMA predicate predicateList | lambda
    if (tokens.size() >= index && tokens.at(index)->GetType() == COMMA) {
        Match(COMMA);
        ParsePredicate();
        ParsePredicateList();
    }
}

void Parser::ParseParameterList() {
    //COMMA parameter parameterList | lambda
    if (tokens.size() >= index && tokens.at(index)->GetType() == COMMA) {
        Match(COMMA);
        ParseParameter();
        ParseParameterList();
    }
}

void Parser::ParseStringList() {
    //COMMA STRING stringList | lambda
    if (tokens.size() >= index && tokens.at(index)->GetType() == COMMA) {
        Match(COMMA);
        Match(STRING);
        ParseStringList();
    }
}

void Parser::ParseIdList() {
    //COMMA ID idList | lambda
    if (tokens.size() >= index && tokens.at(index)->GetType() == COMMA) {
        Match(COMMA);
        Match(ID);
        ParseIdList();
    }
}

void Parser::ParseParameter() {
    //STRING | ID | expression
    if (tokens.size() >= index) {
        if (tokens.at(index)->GetType() == STRING) {
            Match(STRING);
        }
        else if (tokens.at(index)->GetType() == ID) {
            Match(ID);
        }
        else if (tokens.at(index)->GetType() == LEFT_PAREN) {
            ParseExpression();
        }
        else {
            throw tokens.at(index);
        }
    }
}

void Parser::ParseExpression() {
    //LEFT_PAREN parameter operator parameter RIGHT_PAREN
    Match(LEFT_PAREN);
    ParseParameter();
    ParseOperator();
    ParseParameter();
    Match(RIGHT_PAREN);
}

void Parser::ParseOperator() {
    //ADD | MULTIPLY
    if (tokens.size() >= index) {
        if (tokens.at(index)->GetType() == ADD) {
            Match(ADD);
        }
        else if (tokens.at(index)->GetType() == MULTIPLY) {
            Match(MULTIPLY);
        }
        else {
            throw tokens.at(index);
        }
    }
}

void Parser::ParseEOF() {
    Match(EOFILE);
}

void Parser::PrintDatalog() {
    cout << "Success!" << endl;
    
}
