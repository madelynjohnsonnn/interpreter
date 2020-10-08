//
//  Parser.cpp
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Parser.h"
#include "Parameter.h"
#include <vector>
#include <iostream>
using namespace std;

Parser::Parser(vector <Token*> t) {
    index = 0;
    tokens = t;
    datalog = new DatalogProgram(domain);
}

//TODO Datalog Parse();

void Parser::Parse() {
    try {
        ParseDatalogProgram();
        datalog->toString();
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
    datalog->SetDomain(domain);
    Match(RULES);
    Match(COLON);
    ParseRuleList();
    Match(QUERIES);
    Match(COLON);
    ParseQuery();
    ParseQueryList();
    ParseEOF();
}

void Parser::ParseScheme() {
    //ID LEFT_PAREN ID idList RIGHT_PAREN
    Predicate* p = new Predicate();
    Match(ID);
    p->SetName(tokens.at(index - 1)->GetString());
    Match(LEFT_PAREN);
    Match(ID);
    Parameter* par = new PlainParameter(tokens.at(index - 1)->GetString());
    p->parameters.push_back(par);
    ParseIdList(p);
    Match(RIGHT_PAREN);
    datalog->schemes.push_back(p);
}

void Parser::ParseSchemeList() {
    //scheme schemeList | lambda
    if (tokens.at(index)->GetType() == ID) {
        ParseScheme();
        ParseSchemeList();
    }
}

Predicate* Parser::ParseFact() {
    //ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    Predicate* p = new Predicate();
    Match(ID);
    p->SetName(tokens.at(index - 1)->GetString());
    Match(LEFT_PAREN);
    if (tokens.at(index)->GetType() == STRING) {
        Domain(tokens.at(index)->GetString());
    }
    Match(STRING);
    Parameter* par = new PlainParameter(tokens.at(index - 1)->GetString());
    p->parameters.push_back(par);
    ParseStringList(p);
    Match(RIGHT_PAREN);
    Match(PERIOD);
    return p;
}

void Parser::ParseFactList() {
    //fact factList | lambda
    if (tokens.at(index)->GetType() == ID) {
        Predicate* p = ParseFact();
        datalog->facts.push_back(p);
        ParseFactList();
    }
}

Rule* Parser::ParseRule() {
    //headPredicate COLON_DASH predicate predicateList PERIOD
    Rule* rule = new Rule();
    Predicate* hp = ParseHeadPredicate();
    rule->SetHeadPredicate(hp);
    Match(COLON_DASH);
    Predicate* bp = ParseBodyPredicate();
    rule->AddBodyPredicate(bp);
    ParsePredicateList(rule);
    datalog->rules.push_back(rule);
    Match(PERIOD);
    return rule;
}

void Parser::ParseRuleList() {
    //rule ruleList | lambda
    if (tokens.at(index)->GetType() == ID) {
        //Rule* r = new Rule();
        ParseRule();
        ParseRuleList();
    }
}

/*
 void Parser::ParseRuleList(Rule* &r) {
    //rule ruleList | lambda
    if (tokens.at(index)->GetType() == ID) {
        Rule* r = ParseRule();
        ParseRuleList(r);
    }
}
*/

void Parser::ParseQuery() {
    //predicate Q_MARK
    Predicate* p = new Predicate();
    p = ParsePredicate();
    Match(Q_MARK);
    datalog->queries.push_back(p);
}

void Parser::ParseQueryList() {
    //query queryList | lambda
    if (tokens.at(index)->GetType() == ID) {
        ParseQuery();
        ParseQueryList();
    }
}

Predicate* Parser::ParseHeadPredicate() {
    //ID LEFT_PAREN ID idList RIGHT_PAREN
    Predicate* p = new Predicate();
    Match(ID);
    p->SetName(tokens.at(index - 1)->GetString());
    Match(LEFT_PAREN);
    Match(ID);
    Parameter* par = new PlainParameter(tokens.at(index - 1)->GetString());
    p->parameters.push_back(par);
    ParseIdList(p);
    Match(RIGHT_PAREN);
    return p;
}

Predicate* Parser::ParsePredicate() {
    //ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    Predicate* p = new Predicate();
    Match(ID);
    p->SetName(tokens.at(index - 1)->GetString());
    //r->AddBodyPredicate(tokens.at(index - 1)->GetString());
    Match(LEFT_PAREN);
    Parameter* par = ParseParameter();
    p->parameters.push_back(par);
    ParseParameterList(p);
    Match(RIGHT_PAREN);
    return p;
}

Parameter* Parser::ParseParameter() {
    //STRING | ID | expression
    if (tokens.size() >= index) {
        if (tokens.at(index)->GetType() == STRING) {
            Match(STRING);
            Parameter* par = new PlainParameter(tokens.at(index - 1)->GetString());
            return par;
        }
        else if (tokens.at(index)->GetType() == ID) {
            Match(ID);
            Parameter* par = new PlainParameter(tokens.at(index - 1)->GetString());
            return par;
        }
        else if (tokens.at(index)->GetType() == LEFT_PAREN) {
            return ParseExpression();
        }
        else {
            throw tokens.at(index);
        }
    }
    return NULL; //shouldn't reach here
}

void Parser::ParseParameterList(Predicate* &p) {
    //COMMA parameter parameterList | lambda
    if (tokens.size() >= index && tokens.at(index)->GetType() == COMMA) {
        Match(COMMA);
        Parameter* par = ParseParameter();
        p->parameters.push_back(par);
        ParseParameterList(p);
    }
}

void Parser::ParseStringList(Predicate* &p) {
    //COMMA STRING stringList | lambda
    if (tokens.size() >= index && tokens.at(index)->GetType() == COMMA) {
        Match(COMMA);
        
        if (tokens.at(index)->GetType() == STRING) {
            Domain(tokens.at(index)->GetString());
        }
        Match(STRING);
        Parameter* par = new PlainParameter(tokens.at(index - 1)->GetString());
        p->parameters.push_back(par);
        
        ParseStringList(p);
    }
}

void Parser::ParseIdList(Predicate* &p) {
    //COMMA ID idList | lambda
    if (tokens.size() >= index && tokens.at(index)->GetType() == COMMA) {
        Match(COMMA);
        Match(ID);
        
        Parameter* par = new PlainParameter(tokens.at(index - 1)->GetString());
        p->parameters.push_back(par);
        
        ParseIdList(p);
    }
}

void Parser::ParseEOF() {
    Match(EOFILE);
}

void Parser::Domain(string s) {
    domain.insert(s);
}



//RULE STUFF

Predicate* Parser::ParseBodyPredicate() {
    //ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    Predicate* p = new Predicate();
    Match(ID);
    p->SetName(tokens.at(index - 1)->GetString());
    //r->AddBodyPredicate(tokens.at(index - 1)->GetString());
    Match(LEFT_PAREN);
    Parameter* par = ParseParameter();
    p->parameters.push_back(par);
    ParseParameterList(p);
    Match(RIGHT_PAREN);
    return p;
}

Parameter* Parser::ParseExpression() {
    //LEFT_PAREN parameter operator parameter RIGHT_PAREN
    Match(LEFT_PAREN);
    Parameter* left = ParseParameter();
    string op = ParseOperator();
    Parameter* right = ParseParameter();
    Match(RIGHT_PAREN);
    Expression* ex = new Expression(left, right, op);
    return ex;
}

string Parser::ParseOperator() {
    //ADD | MULTIPLY
    if (tokens.size() >= index) {
        if (tokens.at(index)->GetType() == ADD) {
            Match(ADD);
            return tokens.at(index - 1)->GetString();
        }
        else if (tokens.at(index)->GetType() == MULTIPLY) {
            Match(MULTIPLY);
            return tokens.at(index - 1)->GetString();
//            par->SetOp(tokens.at(index - 1)->GetString());
//            Predicate* p = new Predicate();
//            p->parameters.push_back(par);
//            datalog->rules.push_back(p);
        }
        else {
            throw tokens.at(index);
        }
    }
    return NULL;
}

void Parser::ParsePredicateList(Rule* &r) {
    //COMMA predicate predicateList | lambda
    if (tokens.size() >= index && tokens.at(index)->GetType() == COMMA) {
        Match(COMMA);
        Predicate* p = ParsePredicate();
        r->AddBodyPredicate(p);
        ParsePredicateList(r);
    }
}
