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
#include "Parser.h"
#include "Test.h"
#include "DatalogProgram.h"
#include "Interpreter.h"
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream in("/Users/maddie/Downloads/Lab4PassOffCases/4-80/input0.txt");

//    ifstream in(argv[1]);
    stringstream buffer;
    buffer << in.rdbuf();

    Lexer* lexer = new Lexer();
    lexer->run(buffer.str());
    //lexer->PrintTokens();

    Parser* parser = new Parser(lexer->GetTokens());

    DatalogProgram* datalog = parser->Parse1();
    Interpreter* interpreter = new Interpreter(datalog);
    interpreter->Run();

//    delete lexer;
//    delete parser;
//    delete datalog;
//    delete interpreter;
    
//    Test* t = new Test();
//    t->TestJoin();
}
