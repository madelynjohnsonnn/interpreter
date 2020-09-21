//
//  Token.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/14/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Token.h"
#include <iostream>
#include <string>
using namespace std;

//Token::Token(string val, int num) {
////    cout << "string value: " << val << ", lineNumber: " << num << endl;
//    this->value = val;
//    this->lineNum = num;
//    this->type = toToken();
//}

Token::Token(TokenType t, string val, int num) {
//    cout << "Type: " << t << ", string value: " << val << ", lineNumber: " << num << endl;
    this->value = val;
    this->lineNum = num;
    this->type = t;
}

string Token::toString() {
    string returnVal = string("(") + tokenToString() + string(",\"") + string(value) + string("\",") + to_string(lineNum) + string(")");
    return returnVal;
}

string Token::tokenToString() {
    switch(type) {
        case COMMA: return "COMMA"; break;
        case PERIOD: return "PERIOD"; break;
        case Q_MARK: return "Q_MARK"; break;
        case LEFT_PAREN: return "LEFT_PAREN"; break;
        case RIGHT_PAREN: return "RIGHT_PAREN"; break;
        case COLON: return "COLON"; break;
        case COLON_DASH: return "COLON_DASH"; break;
        case MULTIPLY: return "MULTIPLY"; break;
        case ADD: return "ADD"; break;
        case SCHEMES: return "SCHEMES"; break;
        case FACTS: return "FACTS"; break;
        case RULES: return "RULES"; break;
        case QUERIES: return "QUERIES"; break;
        case ID: return "ID"; break;
        case UNDEFINED: return "UNDEFINED"; break;
        case EOFILE: return "EOF"; break;
        case STRING: return "STRING"; break;
        case COMMENT: return "COMMENT"; break;
    }
    return "ERROR";
}

/*
TokenType Token::toToken() {
    if (value == ",") return COMMA;
    else if (value == ".") return PERIOD;
    else if (value == "?") return Q_MARK;
    else if (value == "(") return LEFT_PAREN;
    else if (value == ")") return RIGHT_PAREN;
    else if (value == ":") return COLON;
    else if (value == ":-") return COLON_DASH;
    else if (value == "*") return MULTIPLY;
    else if (value == "+") return ADD;
    else if (value == "Schemes") return SCHEMES;
    else if (value == "Facts") return FACTS;
    else if (value == "Rules") return RULES;
    else if (value == "Queries") return QUERIES;
    else if (value == "") return ID;
    //string case
    //comment case
//    else if (value == "$") return UNDEFINED; //undefined case
//    else if (value == "&") return UNDEFINED; //undefined case
//    else if (value == "^") return UNDEFINED; //undefined case
    //string that doesn't end case     //undefined case
    else if (value == "EOFILE") return EOFILE;
    return UNDEFINED;
}
*/
