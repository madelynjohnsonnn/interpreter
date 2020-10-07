//
//  Token.h
//  lab1
//
//  Created by Maddie Johnson on 9/14/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Token_h
#define Token_h

#include <stdio.h>
#include <string>
using namespace std;

enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, EOFILE};

class Token {
public:
//    Token(string val, int num);
    Token(TokenType t, string val, int num);
    string toString();
    TokenType GetType();
    string tokenToString();
private:
    string value;
    int lineNum;
    TokenType type;
    //TokenType toToken();
};


#endif /* Token_h */
