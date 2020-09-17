//
//  main.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/14/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <streambuf>
#include "Lexer.h"
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream in(argv[1]);

    stringstream buffer;
    buffer << in.rdbuf();
 
    Lexer * lexer = new Lexer();
    lexer->run(buffer.str());
    lexer->PrintTokens();
    
}

//run/interpret results
//error checking throughout documents
