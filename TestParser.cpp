//
//  TestParser.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/6/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "TestParser.h"
#include "Token.h"
#include "Parser.h"
#include <vector>
using namespace std;
#include <iostream>

void TestParser::TestSchemeList() {
    //ID LEFT_PAREN ID idList RIGHT_PAREN
    
    vector <Token*> tokens;
    tokens.push_back(new Token(ID, "ID", 1));
    tokens.push_back(new Token(LEFT_PAREN, "(", 1));
    tokens.push_back(new Token(ID, "ID", 2));
    tokens.push_back(new Token(COMMA, "COMMA", 2));
    tokens.push_back(new Token(ID, "ID", 2));
    tokens.push_back(new Token(RIGHT_PAREN, ")", 2));
    
    
    Parser* p = new Parser(tokens);
    p->ParseScheme();
    cout << "done" << endl;
}
